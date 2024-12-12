# Write your MySQL query statement below
with b as (select actor_id , director_id from ActorDirector)
select *from b group by actor_id,director_id having count(*)>2; 