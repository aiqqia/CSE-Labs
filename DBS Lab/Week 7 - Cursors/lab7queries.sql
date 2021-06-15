declare dt constant varchar(20) := '09/06/2021'; 
cursor c is select * from instructor; 
begin 
    for ins in c loop 
    insert into salaryraise values( ins.id, to_date(dt, 'dd/mm/yyyy'), ins.salary * 0.05 ); 
end loop; 
update instructor set salary = salary * 1.05; 
end;
/


declare 
cursor c is select * from student order by tot_cred asc; 
stu student %rowtype; 
cnt number(5); 
begin 
    cnt := 0; 
    open c; 
    loop fetch c into stu; 
        dbms_output.put_line( 'ID:' || stu.id || ' Name:' || stu.name || ' Dept:' || stu.dept_name || ' Credits:' || stu.tot_cred ); 
        cnt := cnt + 1; 
        exit when cnt >= 10; 
    end loop; 
    close c; 
end;
/

declare 
cursor c is select course_id, title, dept_name, credits, tot 
            from course natural join ( select course_id, count(*) as tot from takes group by course_id ); 
begin 
    for co in c 
    loop dbms_output.put_line( 'ID: ' || co.course_id || ' Title: ' || co.title || ' Dept: ' || co.dept_name || ' Credits: ' || co.credits || ' Total ' || co.tot ); 
    end loop; 
end;
/

declare 
cursor c is select * from takes where course_id = '747'; 
cre student.tot_cred %type; 
cnt number(8); 
begin cnt := 0; 
    for s in c 
    loop select tot_cred into cre from student where id = s.id; 
        if cre < 30 then delete from takes where course_id = '747' and id = s.id; 
            dbms_output.put_line('deleted : ' || s.id || ' credits : ' || cre); 
            cnt := cnt + 1; 
        end if; 
    end loop; 
    dbms_output.put_line( cnt || ' students de-enrolled from the course 747' ); 
end;
/

declare 
cursor c is select * from studenttable for update; 
begin 
    for stu in c 
    loop if stu.gpa > 4 and stu.gpa <= 5 then update studenttable set LetterGrade = 'e' where current of c; 
        elsif stu.gpa > 5 and stu.gpa <= 6 then update studenttable set LetterGrade = 'd' where current of c; 
        elsif stu.gpa > 6 and stu.gpa <= 7 then update studenttable set LetterGrade = 'c' where current of c; 
        elsif stu.gpa > 7 and stu.gpa <= 8 then update studenttable set LetterGrade = 'b' where current of c; 
        elsif stu.gpa > 8 and stu.gpa <= 9 then update studenttable set LetterGrade = 'a' where current of c; 
        elsif stu.gpa > 9 and stu.gpa <= 10 then update studenttable set LetterGrade = 'a+' where current of c; 
        end if; 
    end loop;
end;
/
select * from studenttable;


declare 
cursor c1(c_id teaches.course_id%type) is select * from (instructor natural join teaches) where course_id = c_id; 
temp teaches.course_id%type; 
begin 
    temp := '&Course_ID'; 
    for info in c1(temp) 
    loop dbms_output.put_line(info.name); 
    end loop; 
end; 
/


declare 
cursor a is select unique t.id as s, s.id as i from takes t, teaches s where t.course_id = s.course_id; 
cursor b(s student.id %type, i instructor.id %type) is select unique s_id from advisor where s_id = s and i_id = i; 
st student %rowtype; 
cnt number(8); 
begin
    cnt := 0; 
    for tuple in a 
    loop for stu in b(tuple.s, tuple.i) 
        loop select * into st from student where id = stu.s_id; 
            dbms_output.put_line(st.name || ' ' || st.id || ' ' || st.dept_name); 
            cnt := cnt + 1; 
        end loop;
    end loop; 
    dbms_output.put_line(cnt || ' rows selected'); 
end; 
/

declare 
cursor c is select * from instructor where dept_name = 'Biology' for update; 
cnt number(20); 
temp number(20); 
begin 
    savepoint a; 
    cnt := 0; 
    for ins in c 
    loop cnt := cnt + ins.salary * 1.2; 
        update instructor set salary = salary * 1.2 where current of c; 
    end loop; 
    select budget into temp from department where dept_name = 'Biology'; 
    if temp < cnt then rollback to savepoint a; 
    else commit; 
    end if; 
end; 
/

select * from instructor where dept_name = 'Biology';
select * from department where dept_name = 'Biology';
