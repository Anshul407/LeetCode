# Write your MySQL query statement below
with b as (
select  customer_id from Visits where visit_id not in(select visit_id from Transactions))
select customer_id,count(*)as count_no_trans from b group by customer_id;