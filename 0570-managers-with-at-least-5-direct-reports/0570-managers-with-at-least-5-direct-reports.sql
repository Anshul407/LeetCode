with b as(
select e1.name as name,e1.id as id from Employee as e1 INNER JOIN Employee as e2 on e1.id=e2.managerId),
c as(
select name,count(id)as cnt from b group by id 
)select name from c where cnt>4 || (name is NOT NULL and cnt>4);