# Write your MySQL query statement below
with b as(
select employee_id,department_id from Employee where primary_flag='Y'),
c as(
select employee_id,department_id from Employee where primary_flag='N'and employee_id not in (select employee_id from b))
select *from c union select * from b;
