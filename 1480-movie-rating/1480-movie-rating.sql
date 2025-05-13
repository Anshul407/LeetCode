# Write your MySQL query statement below
with b as(
select user_id,count(*) as c from MovieRating group by user_id)
,c as(
select user_id from b where c in(
select max(c) from b))
, 
gg as(
    select * from MovieRating where Year(created_at)=2020 and Month(created_at)=02
),
d as(
select movie_id,avg(rating) as c from gg group by movie_id)
,e as(
select movie_id from d where c in(
select max(c) from d))
,
f as(
select Movies.title as results from e inner join Movies on e.movie_id=Movies.movie_id order by Movies.title limit 1),
g as(
select Users.name as results from c inner join Users on c.user_id=Users.user_id order by Users.name limit 1)
select * from g
union all
select * from f;


