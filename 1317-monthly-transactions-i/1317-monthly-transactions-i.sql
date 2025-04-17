# Write your MySQL query statement below
with b as(
select *,Date_format(trans_date,'%Y-%m') as month from Transactions)
select month,country,count(*) as trans_count ,sum(state='approved') as approved_count , sum(amount) as trans_total_amount ,sum(amount*(state='approved')) as approved_total_amount  from b group by month,country;