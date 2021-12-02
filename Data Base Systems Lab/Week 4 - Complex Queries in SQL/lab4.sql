select title, count(distinct takes.ID) no_of_students 
from student,takes,course
where student.ID=takes.ID and takes.course_id=course.course_id and student.dept_name=course.dept_name group by title;

select dept_name,count(ID) as total_students from student group by dept_name having count(ID) > 1;

select dept_name,count(course_id) from course group by dept_name;

select dept_name,avg(salary) from instructor group by dept_name having avg(salary)>42000;

select sec_id,count(ID) from takes where semester='Spring' and year=2009 group by sec_id;

select *
from prereq
order by course_id asc;

select * from instructor order by salary desc;

select max(total_salary) from (select dept_name, sum(salary) as total_salary from instructor group by dept_name);

select dept_name, avg_salary from(select dept_name,avg(salary) as avg_salary from instructor group by dept_name) where avg_salary>42000;

select max(enroll) from(select sec_id,count(ID) as enroll from takes where semester='Spring' and year=2010 group by sec_id);//not correct

select sec_id, enroll from(select sec_id,count(ID) as enroll from takes where semester='Spring' and year=2010 group by sec_id) where enroll >=all(select count(ID) as enroll from takes where semester='Spring' and year=2010 group by sec_id);

select distinct name from instructor natural join teaches where course_id in (select distinct course_id from student natural join takes where dept_name='Comp. Sci.');

select dept_name,total,average_salary from(select dept_name,count(*) as total,avg(salary) as average_salary from instructor group by dept_name having count(ID)>2 and avg(salary)>5000);

Alternate:
select dept_name,
    total,
    avg_sal
from(
        select dept_name,
            count(*) as total,
            avg(salary) as avg_sal
        from instructor
        group by dept_name
    )
where total > 2
    and avg_sal > 50000;


with budg(val) as (select max(budget) from department)
select dept_name,budget from budg,department where budg.val=department.budget;

with tot(dept_name,total) as (select dept_name,sum(salary) as tot from instructor group by dept_name), avge(val) as (select avg(total) from tot) select dept_name, total from tot, avge where total>val;

with totl(sec_id, cnt) as (select sec_id, count(distinct ID) from takes where semester='Fall' and year=2009 group by sec_id), mx(val) as (select max(cnt) from totl) select sec_id, cnt from totl, mx where cnt=val;

with t1(dept_name,total_cred) as
    (select dept_name,sum(tot_cred) from student group by dept_name),
    t2(value) as (select total_cred from t1
    where dept_name='Finance')
    select dept_name from t1,t2
    where total_cred>value;

savepoint Q17;
delete from instructor where dept_name='Finance';

savepoint Q18;
delete from course where dept_name='Comp. Sci.';

update student set dept_name='Music' where dept_name='Comp.Sci.';

update instructor 
set salary=case
	when salary>100000
	then salary*1.03
	else
	salary*1.05
    end;
rollback;

