# Write your MySQL query statement below
with b as(
select * from Activity where DATEDIFF('2019-07-27',activity_date)>=0 and DATEDIFF('2019-07-27',activity_date)<30)
SELECT activity_date AS day, 
       COUNT(DISTINCT user_id) AS active_users
FROM b 
GROUP BY activity_date order by activity_date;

