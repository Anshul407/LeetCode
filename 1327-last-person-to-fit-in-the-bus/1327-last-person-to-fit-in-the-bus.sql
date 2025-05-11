# Write your MySQL query statement below
with b as(
select person_name, sum(weight) OVER(order by turn rows between unbounded preceding and current row) as X from Queue),
c as (
select * from b where x<=1000)
select person_name from c where x in (select max(x) as x from c);
