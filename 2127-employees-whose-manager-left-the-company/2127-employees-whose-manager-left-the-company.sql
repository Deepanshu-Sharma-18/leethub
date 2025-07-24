# Write your MySQL query statement below
select e1.employee_id
from (
    select employee_id, manager_id
    from Employees
    where salary < 30000 and manager_id is not null
) e1
left join Employees e2
on e1.manager_id = e2.employee_id
where e2.employee_id is null
order by e1.employee_id