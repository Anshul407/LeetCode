# Write your MySQL query statement below
update Salary
set sex=
CASE sex 
    WHEN 'm' THEN 'f'
    else 'm'
END;
