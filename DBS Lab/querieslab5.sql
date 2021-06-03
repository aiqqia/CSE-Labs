select bdate, address 
from employeeER 
where fname = 'Ayush' and minit = 'F' and lname = 'Goyal'; 
select fname, minit, lname, address 
from employeeER natural join departmentER 
where name = 'CyberSecurity';

select project_code, p.dept_no, lname, address, bdate 
from employeeER e, (select * from projectsER inner join departmentER using(dept_no) where location = 'Winterfell' ) p 
where manager = ssn;

select distinct salary 
from employeeER;

select a.fname, a.lname, b.fname, b.lname 
from employeeER a, employeeER b 
where a.supervisor = b.ssn;

select distinct project_code 
from projectsER 
where project_code in ( select project_code 
                        from worksER natural join employeeER 
                        where lname = 'Chauhan' ) or project_code in ( select project_code 
                                                                       from projectsER inner join ( select d.dept_no, lname 
                                                                                                  from departmentER d, employeeER e 
                                                                                                  where manager = ssn ) using(dept_no) 
                                                                       where lname = 'Chauhan' );

select * 
from employeeER 
where address = 'Winterfell';

select fname, lname, salary*1.01 as increasedsalary
from employeeER e, worksER w, projectsER p 
where e.ssn = w.ssn and w.project_code = p.project_code and p.name = 'DCGANS';

select * 
from employeeER 
where dept_no = 11111111 and salary between 30000 and 40000;

select fname, lname, project_code, dept_no 
from employeeER natural join worksER order by dept_no, lname, fname;

select * 
from employeeER 
where supervisor is null;

select fname, lname 
from employeeER e inner join dependentsER d using(ssn) 
where fname = name and d.sex = e.sex;

select fname, lname 
from employeeER left outer join dependentsER using(ssn) 
where name is null;

select distinct fname, lname 
from ( select * 
       from employeeER, departmentER 
       where manager = ssn ) left outer join dependentsER d using(ssn) 
where d.name is not null;

select ssn 
from worksER 
where project_code = 123456 or project_code = 1234 or project_code = 1234567;

select sum(salary) as sumsalary, max(salary) as maxsalary, min(salary) as minsalary, avg(salary) as avgsalary  
from employeeER;

select sum(salary) as sumsalary, max(salary) as maxsalary, min(salary) as minsalary, avg(salary) as avgsalary 
from ( select * 
       from employeeER inner join departmentER using(dept_no) ) group by name having name = 'CyberSecurity';

with proj(project_code, no_of_emp) 
as (select project_code, count(*) 
    from worksER group by project_code ) 
select project_code, name, no_of_emp 
from proj inner join projectsER using(project_code);

with proj(project_code, no_of_emp) 
as (select project_code, count(*) 
    from worksER group by project_code ) 
select project_code, name, no_of_emp 
from proj inner join projectsER using(project_code) 
where no_of_emp > 2;

with firsts(dept_no, no) as (select dept_no, count(*) 
    from employeeER group by dept_no ), 
second(dept_no, no) as (select dept_no, count(*) 
    from employeeER 
    where salary > 40000 group by dept_no ) 
select a.dept_no, b.no 
from firsts a, second b 
where a.dept_no = b.dept_no and a.no > 5;