# Write your MySQL query statement below
with b as(
select product_id,unit from Orders where month(order_date)=02 and year(order_date)=2020),
c as (
    select product_id,sum(unit)as unit from b group by product_id having sum(unit)>99
)
select Products.product_name,c.unit from Products inner join c on Products.product_id=c.product_id;