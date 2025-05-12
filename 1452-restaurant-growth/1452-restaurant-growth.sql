# Write your MySQL query statement below
with b as(
    select sum(amount) as amount,visited_on from Customer group by visited_on
),
c as
(select visited_on, sum(amount) over(order by visited_on rows between 6 preceding and current row) as sum ,round(avg(amount) over(order by visited_on rows between 6 preceding and current row),2) as average,ROW_NUMBER() over(order by visited_on) as ranking from b)
select visited_on,sum as amount,average as average_amount from c where ranking>=7;