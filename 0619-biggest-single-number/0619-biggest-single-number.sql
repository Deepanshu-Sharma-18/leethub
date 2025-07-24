# Write your MySQL query statement below
select max(num) as num
from (select max(num) as num
from MyNumbers
group by num
having count(num) < 2
) a
