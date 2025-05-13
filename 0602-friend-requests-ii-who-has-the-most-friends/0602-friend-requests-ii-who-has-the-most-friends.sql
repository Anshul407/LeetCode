# Write your MySQL query statement below
with b as(
select requester_id as r from RequestAccepted
UNION ALL
select accepter_id as r from RequestAccepted),
c as(
select r,count(*) as cc from b group by r)
select r as id , cc as num from c where cc in(
select max(cc) as cc from c)
