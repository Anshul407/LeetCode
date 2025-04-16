# Write your MySQL query statement below
select Product.product_name as product_name, Sales.year as year, Sales.price as price from Product inner join Sales on Product.product_id=Sales.product_id;