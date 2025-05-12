# Write your MySQL query statement below
with b as(
select *,DENSE_RANK() Over(partition by departmentId order by salary desc) as ranking from Employee),
c as(
select b.*,c.name as d from Department c inner join b on c.id=b.departmentId)
select d as Department,name as Employee,salary as Salary from c where ranking<=3;