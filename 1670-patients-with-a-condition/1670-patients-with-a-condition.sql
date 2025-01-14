# Write your MySQL query statement below
with b as(
select * from
patients
where 
conditions 
like "% DIAB1%" or 
conditions 
like "DIAB1%")select *from b;

