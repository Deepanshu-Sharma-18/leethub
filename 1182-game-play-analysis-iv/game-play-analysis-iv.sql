# Write your MySQL query statement below
select round(count(a2.player_id) /  count( a1.player_id) ,2) as fraction 
from Activity a1
left outer join Activity a2
on a1.player_id = a2.player_id  and datediff(a2.event_date , a1.event_date) = 1
WHERE (a1.player_id,a1.event_date) IN
  (SELECT player_id,min(event_date) FROM Activity 
   GROUP BY player_id)

