# Write your MySQL query statement below
with b as(
select machine_id,max(timestamp)-min(timestamp) as diff from Activity group by machine_id,process_id)
select machine_id, round(avg(diff),3)as processing_time from b group by machine_id;