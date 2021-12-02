drop table Part;
drop table Service;

create table Part(
    PartNo number(2),
    PartName varchar(2),
    VehicleType varchar(2),
    UnitPrice number(5),
    SalesPrice number(5),
    primary key(PartNo),
    check(VehicleType in ('V1','V2','V3','V4','V5')),
	check( UnitPrice > 0 and SalesPrice > 0));

create table Service(
    ServiceNo number(2),
    PartNo number(2),
    ServiceDate date,
    CustomerNo varchar(2),
    Qty number(5),
    primary key(ServiceNo,PartNo),
    foreign key (PartNo) references Part(PartNo));

insert into Part values(1, 'P1', 'V1', 10, 12);
insert into Part values(2, 'P2', 'V2', 100, 110);
insert into Part values(3, 'P3', 'V1', 150, 175);
insert into Part values(4, 'P4', 'V3', 200, 250);
insert into Part values(5, 'P5', 'V2', 75, 90);

insert into Service values(1, 1, '01-Jan-17', 'C1', 5);
insert into Service values(1, 3, '01-Jan-17', 'C1', 4);
insert into Service values(2, 3, '05-Feb-18', 'C2', 10);
insert into Service values(3, 1, '15-May-18', 'C3', 9);
insert into Service values(4, 1, '03-Jun-19', 'C1', 5);