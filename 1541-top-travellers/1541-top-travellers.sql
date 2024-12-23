-- # Write your MySQL query statement below
-- with b(
with b as (
select Users.name,sum(Rides.distance) as travelled_distance from Users left join Rides on Users.id=Rides.user_id group by Users.id)
select name,coalesce(travelled_distance,0) as travelled_distance from b order by travelled_distance desc,name asc;

-- select *from b order by distance,name desc;