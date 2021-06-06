DECLARE
    message varchar2(20):='Hello, World!';
BEGIN
    dbms_output.put_line(message);
END;
/

DECLARE
    roll_number StudentTable.rollNo%TYPE;
    score StudentTable.gpa%TYPE;
BEGIN
    roll_number:='&r';
    select gpa into score from StudentTable where rollNo=roll_number;
    dbms_output.put_line(score);
END;
/

DECLARE
    roll_number StudentTable.rollNo%TYPE;
    score StudentTable.gpa%TYPE;
BEGIN
    roll_number:='&r';
    select gpa into score from StudentTable where rollNo=roll_number;
IF score between 0 and 4 THEN
    dbms_output.put_line('F');
ELSIF score between 4 and 5 then
	dbms_output.put_line('E');
ELSIF score between 5 and 6 then
	dbms_output.put_line('D');
ELSIF score between 6 and 7 then
	dbms_output.put_line('C');
ELSIF score between 7 and 8 then
	dbms_output.put_line('B');
ELSIF score between 8 and 9 then
	dbms_output.put_line('A');	
ELSE 
	dbms_output.put_line('A+');									
END IF;
END;
/

DECLARE
    issue_date date;
    return_date date;
    diff number;
    fine number;
BEGIN
    issue_date:= TO_DATE('&issue_date','DD-MM-YYYY');
    return_date:= TO_DATE('&return_date','DD-MM-YYYY');
    diff:=TO_DATE(return_date, 'DD-MM-YYYY') - TO_DATE(issue_date, 'DD-MM-YYYY');
IF diff between 0 and 7 THEN
    fine:=0;
ELSIF diff between 8 and 15 THEN
    fine := (diff-7)*1;
ELSIF diff between 16 and 30 THEN
    fine := 8 + (diff-15)*2;
ELSE
    fine := 8 + 30 + (diff-30)*5;
END IF;
dbms_output.put_line('FINE = ' || fine);
END;
/

DECLARE
    roll_no StudentTable.rollNo%TYPE;
    score StudentTable.gpa%TYPE;
BEGIN
    roll_no := 1;
LOOP
IF roll_no > 5 THEN
    EXIT;
END IF;
select gpa into score from StudentTable where rollNo=roll_no;
IF score between 0 and 4 THEN
    dbms_output.put_line('Grade : F');
ELSIF score between 4 and 5 THEN
    dbms_output.put_line('Grade : E');
ELSIF score between 5 and 6 THEN
    dbms_output.put_line('Grade : D');
ELSIF score between 6 and 7 THEN
    dbms_output.put_line('Grade : C');
ELSIF score between 7 and 8 THEN
    dbms_output.put_line('Grade : B');
ELSIF score between 8 and 9 THEN
    dbms_output.put_line('Grade : A');
ELSE
    dbms_output.put_line('Grade : A+');
END IF;
roll_no := roll_no + 1;
END LOOP;
END;
/

DECLARE
    roll_no StudentTable.rollNo%TYPE;
    score StudentTable.gpa%TYPE;
BEGIN
    roll_no := 1;
while(roll_no<6)
LOOP
IF roll_no > 5 THEN
    EXIT;
END IF;
select gpa into score from StudentTable where rollNo=roll_no;
IF score between 0 and 4 THEN
    update StudentTable set LetterGrade='F' where rollNo=roll_no;
ELSIF score between 4 and 5 THEN
    update StudentTable set LetterGrade='E' where rollNo=roll_no;
ELSIF score between 5 and 6 THEN
    update StudentTable set LetterGrade='D' where rollNo=roll_no;
ELSIF score between 6 and 7 THEN
    update StudentTable set LetterGrade='C' where rollNo=roll_no;
ELSIF score between 7 and 8 THEN
    update StudentTable set LetterGrade='B' where rollNo=roll_no;
ELSIF score between 8 and 9 THEN
    update StudentTable set LetterGrade='A' where rollNo=roll_no;
ELSE
    update StudentTable set LetterGrade='A+' where rollNo=roll_no;
END IF;
roll_no := roll_no + 1;
END LOOP;
END;
/

DECLARE
    i number := 1;
    roll_no StudentTable.rollNo%TYPE;
    score StudentTable.gpa%TYPE;
    highest StudentTable.gpa%TYPE;
BEGIN
    roll_no := 1;
select gpa into highest from StudentTable where rollNo=roll_no;
FOR i IN 1..5 LOOP
select gpa into score from StudentTable where rollNo=roll_no;
IF score>highest THEN
    highest:=score;
END IF;
roll_no := roll_no + 1;
END LOOP;
dbms_output.put_line('Max grade : ' || highest);
END;
/

DECLARE
    g char(2);
    roll_no StudentTable.rollNo%TYPE;
    score StudentTable.gpa%TYPE;
BEGIN
    roll_no := 1;
<<loopbegin>>
select gpa into score from StudentTable where rollNo=roll_no;
IF score between 0 and 4 THEN
    g := 'F';
ELSIF score between 4 and 5 THEN
    g := 'E';
ELSIF score between 5 and 6 THEN
    g := 'D';
ELSIF score between 6 and 7 THEN
    g := 'C';
ELSIF score between 7 and 8 THEN
    g := 'B';
ELSIF score between 8 and 9 THEN
    g := 'A';
ELSE
    g := 'A+';
END IF;
dbms_output.put_line('Roll no : '||roll_no||' Grade : '||g);
roll_no := roll_no + 1;
IF roll_no<6 THEN
    GOTO loopbegin;
END IF;
END;
/

DECLARE
    Multiple_Instructor Exception;
    inst instructor%ROWTYPE;
    inp instructor.name%TYPE;
    n number(10);
BEGIN
    inp := '&name';
select count(id) into n from instructor group by name having name=inp;
IF n>1 THEN
    RAISE Multiple_Instructor;
ELSE
    select * into inst from instructor where instructor.name = inp;
    dbms_output.put_line(inst.id ||' '|| inst.name ||' '|| inst.dept_name ||' '|| inst.salary);
END IF;
EXCEPTION
WHEN Multiple_Instructor THEN
    dbms_output.put_line('Duplicate names found!');
END;
/

DECLARE
    Multiple_Instructor Exception;
    inst instructor%ROWTYPE;
    inp instructor.name%TYPE;
    n number(10);
BEGIN
inp := '&name';
select count(id) into n from instructor group by name having name=inp;
IF n>1 THEN
    RAISE Multiple_Instructor;
ELSIF n=1 THEN
    select * into inst from instructor where instructor.name = inp;
    dbms_output.put_line(inst.id ||' '|| inst.name ||' '|| inst.dept_name ||' '|| inst.salary);
ELSE
    RAISE NO_DATA_FOUND;
END IF;
EXCEPTION
WHEN Multiple_Instructor THEN
    dbms_output.put_line('Duplicate names found!');
WHEN NO_DATA_FOUND THEN
    dbms_output.put_line('Instructor not found!');
END;
/

DECLARE
    Out_of_range Exception;
    roll_no StudentTable.rollNo%TYPE;
    score StudentTable.gpa%TYPE;
BEGIN
roll_no := 1;
while(roll_no<6)
LOOP
IF roll_no > 5 THEN
    EXIT;
END IF;
select gpa into score from StudentTable where rollNo=roll_no;
IF score between 0 and 4 THEN
    update StudentTable set LetterGrade='F' where rollNo=roll_no;
ELSIF score between 4 and 5 THEN
    update StudentTable set LetterGrade='E' where rollNo=roll_no;
ELSIF score between 5 and 6 THEN
    update StudentTable set LetterGrade='D' where rollNo=roll_no;
ELSIF score between 6 and 7 THEN
    update StudentTable set LetterGrade='C' where rollNo=roll_no;
ELSIF score between 7 and 8 THEN
    update StudentTable set LetterGrade='B' where rollNo=roll_no;
ELSIF score between 8 and 9 THEN
    update StudentTable set LetterGrade='A' where rollNo=roll_no;
ELSIF score between 9 and 10 THEN
    update StudentTable set LetterGrade='A+' where rollNo=roll_no;
ELSE
    RAISE Out_of_range;
END IF;
roll_no := roll_no + 1;
END LOOP;
EXCEPTION
WHEN Out_of_range THEN
    dbms_output.put_line('GPA is out of range!');
END;
/