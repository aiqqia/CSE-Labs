set serveroutput on

create table StudentTable(
rollNo number(2),
gpa numeric(4,2));

insert into StudentTable values(1,5.8);
insert into StudentTable values(2,6.5);
insert into StudentTable values(3,3.4);
insert into StudentTable values(4,7.8);
insert into StudentTable values(5,9.5);

alter table StudentTable add LetterGrade varchar2(2);

update StudentTable set gpa=10.7 where rollNo=5;
