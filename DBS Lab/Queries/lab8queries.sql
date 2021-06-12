--1

CREATE OR REPLACE PROCEDURE listInst (deptName Instructor.dept_name%type) IS
CURSOR curseInst (deptName Instructor.dept_name%type) IS
SELECT name FROM Instructor WHERE dept_name = deptName;
CURSOR curseCourses (deptName Instructor.dept_name%type) IS
SELECT course_id FROM Course WHERE dept_name = deptName;
BEGIN
    dbms_output.put_line('...........................');
    dbms_output.put_line('-- DEPARTMENTs INSTRUCTORS --');
    FOR row IN curseInst (deptName)
    LOOP
        dbms_output.put_line(' '||row.name);
    END LOOP;
    dbms_output.put_line('...........................');
    dbms_output.put_line('-- COURSES --');
    FOR row IN curseCourses (deptName) LOOP
        dbms_output.put_line(' ' || row.course_id);
    END LOOP;
END;
/

DECLARE
BEGIN
listInst('Physics');
END;
/

--2

CREATE OR REPLACE PROCEDURE course_popular IS
CURSOR cursepop IS
WITH studentenroll as (select course_id,count(distinct ID) as student_count from takes group by course_id),
studenmod as (select course_id,student_count,dept_name from studentenroll natural join course),
deptmax as (select max(student_count) as dept_high,dept_name from course natural join studenmod group by dept_name)
select dept_high,course_id,dept_name from studenmod natural join deptmax where student_count=dept_high;
BEGIN
    FOR row IN cursepop LOOP
        dbms_output.put_line('Department name : '||row.dept_name);
        dbms_output.put_line(' Course ID : ' || row.course_id);
        dbms_output.put_line('Number of student enrolled : '||row.dept_high);
        dbms_output.put_line('---------------------------------------------------');
    END LOOP;
END;
/

DECLARE
begin
    dbms_output.put_line('----- ALL DEPARTMENTS HIGHEST ENROLLED COURSES ------');
    course_popular;
end;
/

--3

CREATE OR REPLACE FUNCTION square (x number)
RETURN number AS s number;
begin
    s := x * x;
    RETURN s;
end;
/

DECLARE
begin
    dbms_output.put_line('5 ^ 2 = '||square(5));
end;
/

--4

CREATE OR REPLACE FUNCTION department_highest (dName Department.dept_name%type)
RETURN Instructor.salary%type as
pop Instructor.salary%type;
begin
    select max(salary) into pop 
    from Instructor group by Instructor.dept_name having Instructor.dept_name in (select dept_name 
                                                                                  from Instructor 
                                                                                  where dept_name = dName);
    return pop;
end;
/

DECLARE
    maxs Instructor.salary%type;
    cursor c1 is select distinct dept_name from department;
begin
    for dn in c1 loop
        maxs := department_highest(dn.dept_name);
        dbms_output.put_line('Highest paid salary in '||dn.dept_name||' is : ' || maxs);
    end loop;
end;
/

--5

CREATE or REPLACE trigger log_change_Takes
BEFORE INSERT OR UPDATE-- OF id,course_id,sec_id,semester,year,grade
OR DELETE on takes
FOR EACH ROW
begin
    case
        WHEN INSERTING THEN
        insert into log_change_Takes values (current_timestamp,'ins',:NEW.id,:NEW.course_id,:NEW.sec_id,:NEW.semester,:NEW.year,:NEW.grade);
        WHEN DELETING THEN
        insert into log_change_Takes values (current_timestamp,'del',:OLD.id,:OLD.course_id,:OLD.sec_id,:OLD.semester,:OLD.year,:OLD.grade);
        WHEN UPDATING THEN
        insert into log_change_Takes values (current_timestamp,'upd',:NEW.id,:NEW.course_id,:NEW.sec_id,:NEW.semester,:NEW.year,:NEW.grade);
    end case;
end;
/

delete from takes where id = '00128' and course_id = 'CS-101';
insert into takes values ('00128', 'CS-101', '1', 'Fall', '2009', 'A');
update takes set grade = 'B' where id = '98988' and course_id = 'BIO-301';

select * from log_change_Takes;

--6

create or replace trigger old_data_inst
Before update on instructor for each row
begin
    insert into old_data_inst values (:old.id,:old.name,:old.dept_name,:old.salary);
end;
/

update instructor set salary = 91000 where name = 'Wu';

select * from old_data_inst;

--7

CREATE or REPLACE TRIGGER Inst_trig
BEFORE INSERT or UPDATE on Instructor
FOR EACH ROW
DECLARE
bud number(10);
BEGIN
Select budget into bud from department where dept_name=:new.dept_name;
IF :new.name like '%0%' or :new.name like '%1%' or :new.name like '%2%' or :new.name like '%3%' or :new.name like '%4%'
or :new.name like '%5%' or :new.name like '%6%' or :new.name like '%7%' or :new.name like '%8%' or :new.name like '%9%' then
RAISE_APPLICATION_ERROR(-20000,'Insert is denied');
END IF;
IF :new.salary<=0 or :new.salary>bud then
RAISE_APPLICATION_ERROR(-20000,'Insert is denied');
END IF;
END;
/

--8

create or replace trigger client_audit
BEFORE UPDATE or INSERT on client
FOR EACH ROW
begin
    case
        WHEN UPDATING THEN
            insert into audit_client values (:OLD.c_no,:OLD.name,:OLD.bal_due,'upd',NULL,sysdate);
        WHEN DELETING THEN
            insert into audit_client values (:OLD.c_no,:OLD.name,:OLD.bal_due,'del',NULL,sysdate);
    end case;
end;
/

--9

CREATE or REPLACE trigger advisor_update
INSTEAD of DELETE on adv_stu
FOR EACH ROW
begin
    delete from advisor where s_id = :OLD.s_id;
end;
/


create view Advisor_Student as select s.name s_name, a.S_ID, a.I_ID, i.name i_name from student s, advisor a, instructor i 
where a.S_ID = s.ID and a.I_ID = i.ID;

create or replace trigger advisor_trigger
instead of delete on Advisor_Student
for each row
begin
delete from advisor where advisor.S_ID = :old.S_ID;
end;
/

delete from Advisor_Student where S_ID = '98988';



create or replace trigger advisor_trigger
instead of delete on Advisor_Student
for each row
begin
delete from advisor where advisor.S_ID = :old.S_ID;
end;
/

delete from Advisor_Student where S_ID = '98988';

--End