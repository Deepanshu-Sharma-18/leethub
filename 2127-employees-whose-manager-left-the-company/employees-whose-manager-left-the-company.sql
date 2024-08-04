# Write your MySQL query statement below
select e1.employee_id
from Employees e1
left join Employees e2
on e1.manager_id = e2.employee_id
where e2.employee_id is null and e1.salary < 30000 and e1.manager_id is not null
order by e1.employee_id;


-- select ifNULL((select e2.employee_id from Employee e2 where e2.employee_id = e1.manager_id) , e1.employee_id) as employee_id
-- from Employees e1
-- where e1.salary < 30000