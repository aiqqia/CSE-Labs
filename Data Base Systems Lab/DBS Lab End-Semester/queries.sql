--1

(select PartName
 from Part)
minus
(select PartName
 from Service natural join Part);


--2

with customerCount(CustomerNo, cnt) as (select CustomerNo, count(*) as cnt
	                                    from Service group by CustomerNo),
     customerMaxCount(val) as (select max(cnt)
	                      from customerCount)
select CustomerNo
from customerCount,customerMaxCount
where cnt = val;


--3

select unique(ser.CustomerNo)
from Service ser
where not exists (
		(select PartNo
	     from Part
		 where VehicleType = 'V1')
		minus
		(select unique PartNo
		 from Service
		 where CustomerNo = ser.CustomerNo));


--PL/SQL 

set serveroutput on;

DECLARE
    Invalid_PartNo Exception;
    total number;
    temp Part.PartNo%Type;
    p Part.PartNo%Type;
    unitp Part.UnitPrice%Type;
    salesp Part.SalesPrice%Type;
    profit number := 0;
BEGIN
    p := &PartNo;

    select count(*) into temp from Part where PartNo = p; 
    IF temp = 0 THEN 
        RAISE Invalid_PartNo;
    END IF;

    select count(*) into total from Service where PartNo = p;
    select UnitPrice into unitp from Part where PartNo = p;
    select SalesPrice into salesp from Part where PartNo = p;
    profit := total * (salesp-unitp);
  
    dbms_output.put_line('Profit for part per quantity ' || p || ' is ' || profit);

    Exception
        WHEN Invalid_PartNo THEN
            dbms_output.put_line('Invalid Part Number!');
        WHEN OTHERS THEN
            dbms_output.put_line('ERROR!');
END;
/


--THE END
set serveroutput on;

declare
    Invalid_PartNo Exception;
    cursor c1 is select * from Part natural join Service;
    cursor c2 is select * from Part;
    partn Service.PartNo%TYPE;
    profit Part.SalesPrice%TYPE := 0;
    countPart number :=0;
begin
    partn:=&partNo;
    for q in c2
        loop
        if q.PartNo = partn then
        countPart:=countPart+1;
        end if;
        end loop;
    if countPart = 0 then 
    raise Invalid_PartNo;
    end if;
    for p in c1
        loop
        if p.PartNo = partn then
        profit := profit + (p.SalesPrice - p.UnitPrice) * p.Qty;
        end if;
        end loop;
    dbms_output.put_line('Total Profit for part : '||profit);

    Exception
        when Invalid_PartNo then
            dbms_output.put_line('Invalid part number');
        when others then
            dbms_output.put_line('Error');
end;
/

--THE END
