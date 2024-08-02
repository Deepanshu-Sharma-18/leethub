# Write your MySQL query statement below
select d.unique_id ,e.name 
from Employees as e
left join EmployeeUNI as d
on e.id = d.id;
