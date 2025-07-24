# Write your MySQL query statement below
select round(
    count(*) / (select count(*) from (
        select distinct player_id from Activity
    ) ac) , 2
) as fraction
from Activity a1
join (
    select player_id, min(event_date) as event_date
    from Activity 
    group by player_id
) a2
on a1.player_id = a2.player_id and datediff(a1.event_date, a2.event_date) = 1
