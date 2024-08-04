# Write your MySQL query statement below
select p.product_name , sum(o.unit) as unit
from Orders o
join Products p
on p.product_id = o.product_id
where Month(o.order_date) = 02 and Year(o.order_date) = 2020
group by o.product_id 
having sum(o.unit) >= 100;
