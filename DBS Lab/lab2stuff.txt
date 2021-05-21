create table EMPLOYEE(
emp_no number(10) PRIMARY KEY,
emp_name varchar(20) NOT NULL,
gender varchar(1) NOT NULL,
salary number(10) NOT NULL,
address varchar(20) NOT NULL);

alter table EMPLOYEE add check(gender in ('M','F'));


create table DEPARTMENT(
dept_no number(10) PRIMARY KEY,
dept_name varchar(20) NOT NULL UNIQUE,
location varchar(20));


alter table EMPLOYEE add(dept_no number(10));
alter table EMPLOYEE add FOREIGN KEY(dept_no) references DEPARTMENT(dept_no);


insert into DEPARTMENT(dept_no,dept_name,location) values(101,'Worker','Hyderabad');
insert into DEPARTMENT(dept_no,dept_name,location) values(102,'Ayush','Kolkata');
insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dept_no) values(1101,'Dipesh','M',1000,'Hyderabad',101);
insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dept_no) values(1102,'AG','M',2000,'Manipal',102);


insert into DEPARTMENT(dept_no,dept_name,location) values(101,'Woek','Hyderabad');
insert into DEPARTMENT(dept_no,dept_name,location) values(102,'Polu','Manipal');
insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dept_no) values(001,'DipeshSingh','M',500,'Hyderabad',101);
insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dept_no) values(002,'AG','M',1000,'Manipal',102);


alter table EMPLOYEE drop constraint abc;
alter table Employee drop constraint SYS_C007031;
select constraint_name, table_name, constraint_type from user_constraints;
alter table Employee add constraint FK foreign key(Dno) references Department(DeptNo) on delete cascade;

select name, course_id as c_name from student natural join takes where takes.year=2015;

select distinct a.name, a.salary as inst_salary from instructor a, instructor b where b.dept_name='Comp. Sci.' and a.salary>b.salary;


alter table EMPLOYEE modify(salary default 10000);