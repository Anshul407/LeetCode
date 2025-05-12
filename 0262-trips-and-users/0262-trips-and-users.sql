# Write your MySQL query statement below
with a as
(select a.users_id uid,a.banned uban,b.driver_id did,b.city_id cid,b.status st,b.request_at date from Users a inner join Trips b on
a.users_id=b.client_id),
b as
(select a.uban,a.st,a.date as dd, u.banned from users u inner join a 
on u.users_id=a.did where uban='No' and date between '2013-10-01' and '2013-10-03'),
c as (
select *,CASE
            WHEN st='Completed'
            then 0
            else 1
            END AS Status
from b where banned='NO')
SELECT 
    dd AS Day, 
    round((SUM(status) / COUNT(*)*1.0),2) AS 'Cancellation Rate' 
FROM c 
GROUP BY dd;
