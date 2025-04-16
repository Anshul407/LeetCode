with b as (
    select Users.user_id as u,Register.contest_id as c from Users INNER JOIN Register on
    Users.user_id=Register.user_id
),
x as(
    select count(distinct user_id)as t from Users
)
select c as contest_id ,round((count(c)/(select t from x)*100),2) as percentage from b group by c order by percentage DESC, contest_id ;