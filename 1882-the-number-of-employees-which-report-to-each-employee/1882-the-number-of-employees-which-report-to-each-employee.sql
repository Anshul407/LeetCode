# Write your MySQL query statement below
with b as(
select e1.employee_id,e1.name,e2.age from Employees as e1 INNER JOIN Employees as e2 on
e1.employee_id=e2.reports_to)
select employee_id,name,count(*)as reports_count, round(avg(age),0) as average_age from b group by employee_id order by employee_id;