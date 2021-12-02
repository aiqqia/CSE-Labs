drop table employeeER;
drop table departmentER;
drop table locationsER;
drop table dependentsER;
drop table projectsER;
drop table worksER;

create table employeeER(
    fname varchar(20),
    minit varchar(1),
    lname varchar(20),
    bdate varchar(20),
    address varchar(50),
    ssn number(20),
    sex char(1),
    supervisor number(20),
    salary number(10),
    dept_no number(20),
    primary key(ssn)
);
--
insert into employeeER values('Dipesh','S','Chauhan','14-01-2002','Winterfell',190905520,'M',190900000,100000,11111111);
insert into employeeER values('Hemangi','J','Jain','28-06-2001','Winterfell',190905486,'F',190905520,40000,11111111);
insert into employeeER values('Shreya','F','Srikrishna','29-06-2000','King''s Landing',180905154,'F',190905520,25000,11111111);
insert into employeeER values('Ayush','F','Goyal','01-01-2000','King''s Landing',190905522,'M',180905154,10000,11111111);
insert into employeeER values('Ina','G','Goel','17-06-2000','Dorne',190911224,'F',190900000,200000,22222222);
insert into employeeER values('Kaushikee','D','Agnihotri','02-09-2000','Dorne',190907160,'F',190911224,30000,22222222);
insert into employeeER values('Parikalp','A','Singh','01-01-2000','Arryn',190905356,'M',190907160,6000,22222222);
insert into employeeER values('Naman','I','Goel','01-01-2001','Arryn',190905521,'M',190911224,20000,22222222);
insert into employeeER values('Abheesht','R','Roy','11-10-2000','Winterfell',190911066,'M',190900000,400000,33333333);
insert into employeeER values('Vedant','R','Das','01-01-1999','Winterfell',190905160,'M',190911066,20000,33333333);
insert into employeeER values('Nishika','N','Agarwal','01-01-2002','Arryn',190905523,'F',190911066,30000,33333333);
insert into employeeER values('Pritima','C','Singh','28-03-1976','Winterfell',190900000,'F',190900000,900000,11111111);
--
alter table employeeER add foreign key (supervisor) references employeeER(ssn);
--


create table departmentER(
    name varchar(20),
    dept_no number(20),
    emp_count number(10),
    manager number(20),
    start_date varchar(20),
    primary key(dept_no),
    foreign key(manager) references employeeER(ssn)
);
--
insert into departmentER values('Web Development',11111111,5,190905520,'02-06-2021');
insert into departmentER values('CyberSecurity',22222222,4,190911224,'02-04-2021');
insert into departmentER values('Machine Learning',33333333,3,190911066,'24-03-2021');
--
alter table employeeER add foreign key (dept_no) references departmentER(dept_no);
--



create table locationsER(
    dept_no number(20),
    area varchar(20),
    primary key (dept_no, area),
    foreign key (dept_no) references departmentER(dept_no)
);
--
insert into locationsER values(11111111, 'Winterfell');
insert into locationsER values(11111111, 'King''s Landing');
insert into locationsER values(22222222, 'Dorne');
insert into locationsER values(22222222, 'Arryn');
insert into locationsER values(33333333, 'Wintefell');
insert into locationsER values(33333333, 'Arryn');
--


create table dependentsER(
    ssn number(20),
    name varchar(20),
    sex char(1),
    bdate varchar(20),
    relationship varchar(20),
    primary key (ssn, name),
    foreign key (ssn) references employeeER(ssn)
);
--
insert into dependentsER values(190905520,'Pritima','F','28-03-1976','Mother');
insert into dependentsER values(190905520,'Harshita','F','18-09-2002','Sister');
--


create table projectsER(
    dept_no number(20),
    location varchar(20),
    name varchar(20),
    project_code number(20),
    primary key(project_code),
    foreign key(dept_no) references departmentER(dept_no)
);
--
insert into projectsER values(11111111, 'Winterfell', 'Web Scraper', 123456);
insert into projectsER values(11111111, 'King''s Landing', 'Forms', 1234567);
insert into projectsER values(22222222, 'Winterfell', 'Password Hashing', 123);
insert into projectsER values(33333333, 'Winterfell', 'DCGANS', 1234);
--


create table worksER(
    ssn number(20),
    project_code number(20),
    hours number(10),
    primary key(ssn, project_code),
    foreign key(ssn) references employeeER(ssn),
    foreign key(project_code) references projectsER(project_code)
);
--
insert into worksER values(190905520, 123456, 12);
insert into worksER values(190905520, 1234567, 30);
insert into worksER values(180905154, 123456, 24);
insert into worksER values(190905486, 1234567, 56);
insert into worksER values(190911224, 123, 105);
insert into worksER values(190905521, 123, 30);
insert into worksER values(190911066, 1234, 300);
insert into worksER values(190905523, 1234, 41);
