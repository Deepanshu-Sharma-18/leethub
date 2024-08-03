# Write your MySQL query statement below
select customer_id
from (
    select  distinct * from Customer
) as t
group by customer_id
having count(product_key) = (select count(product_key) from Product);
