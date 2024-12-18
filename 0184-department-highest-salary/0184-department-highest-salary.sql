-- with b as 
-- (select Department.name as Department,Employee.name as Employee,Employee.salary as Salary from Department join Employee on Department.id=Employee.departmentId)
-- select * from b where Salary in (select max(Salary),Department from b group by Department);
select Department.name as Department,Employee.name as Employee,Employee.salary as Salary from Department left join Employee on Department.id=Employee.departmentId  where salary=(select max(salary) from Employee where Department.id=Employee.departmentId)