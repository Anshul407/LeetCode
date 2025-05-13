# Write your MySQL query statement below
with x as(
select *from Delivery where (customer_id,order_date) in(
select customer_id,first_value(order_date) over(partition by customer_id order by order_date) as o from Delivery))
,b as(
select 
    *,
    CASE 
        WHEN
            order_date=customer_pref_delivery_date
            then 1
            else 0
        END AS r
from x)
select ROUND(SUM(r) / COUNT(*) * 100, 2) as immediate_percentage from b;