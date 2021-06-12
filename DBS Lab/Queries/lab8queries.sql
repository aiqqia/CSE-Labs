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
BEGIN
    dbms_output.put_line('----- ALL DEPARTMENTS HIGHEST ENROLLED COURSES ------');
    course_popular;
END;
/

--3

CREATE OR REPLACE FUNCTION square (x number)
RETURN number AS s number;
BEGIN
    s := x * x;
    RETURN s;
END;
/

DECLARE
BEGIN
    dbms_output.put_line('5 ^ 2 = '||square(5));
END;
/

--4

CREATE OR REPLACE FUNCTION department_highest (dName Department.dept_name%type)
RETURN Instructor.salary%type as
pop Instructor.salary%type;
BEGIN
    select max(salary) into pop 
    from Instructor group by Instructor.dept_name having Instructor.dept_name in (select dept_name 
                                                                                  from Instructor 
                                                                                  where dept_name = dName);
    return pop;
END;
/

DECLARE
    maxs Instructor.salary%type;
    cursor c1 is select distinct dept_name from department;
BEGIN
    for dn in c1 loop
        maxs := department_highest(dn.dept_name);
        dbms_output.put_line('Highest paid salary in '||dn.dept_name||' is : ' || maxs);
end loop;
END;
/

--5

