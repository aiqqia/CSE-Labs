--5

create table log_change_Takes (
        toc timestamp,
        type varchar(3),
        ID varchar(5),
        course_id varchar(8),
        sec_id varchar(8),
        semester varchar(6),
        year numeric(4,0),
        grade varchar(2),
        primary key (toc, ID, course_id, sec_id, semester, year),
        foreign key (course_id,sec_id, semester, year) references section
        on delete cascade,
        foreign key (ID) references student
        on delete cascade);

--6

create table old_data_inst(
    id varchar(8),
    name varchar(20),
    dept_name varchar(20),
    salary numeric(8,2),
    primary key (id));

--7


--8

CREATE table client(
    c_no varchar(5) primary key,
    name varchar(20),
    address varchar(100),
    bal_due number);

insert into client values ('01', 'Ayush','Kolkata',10000);
insert into client values ('02', 'Dipesh','Delhi',20000);
insert into client values ('03', 'Rishav','Jaipur',30000);

create table audit_client(
    c_no varchar(5),
    name varchar(20),
    bal_due number,
    op varchar(3),
    user_id varchar(5) default('00000'),
    opDate date);

--9

create view Advisor_Student as select s.name s_name, a.S_ID, a.I_ID, i.name i_name from student s, advisor a, instructor i 
where a.S_ID = s.ID and a.I_ID = i.ID;

create or replace view adv_stu as 
    select s_id,S.name as s_name,
           S.dept_name as s_dept,
           S.tot_cred,
           i_id,
           I.name as i_name,
           i.dept_name as i_dept,
           I.salary
    from ((student S join advisor A on s.id=a.s_id) join instructor I on i_id=i.id);

--End