# Write your MySQL query statement below
select distinct l1.num as consecutiveNums
from Logs l1
join Logs l2
on l1.num = l2.num
join Logs l3
on l2.num = l3.num
where l1.id + 1 = l2.id and l2.id + 1 = l3.id
