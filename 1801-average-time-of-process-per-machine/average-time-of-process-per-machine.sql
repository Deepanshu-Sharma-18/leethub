# Write your MySQL query statement below
select a1.machine_id , round(sum(a2.timestamp - a1.timestamp)/count(a1.machine_id),3) as processing_time
from Activity a1
inner join Activity a2
on a1.machine_id = a2.machine_id and a1.process_id = a2.process_id and a1.activity_type != a2.activity_type and a1.timestamp < a2.timestamp
group by a1.machine_id;