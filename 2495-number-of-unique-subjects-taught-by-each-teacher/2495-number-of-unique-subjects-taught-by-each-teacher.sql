# Write your MySQL query statement below
select teacher_id , count(*) as cnt
from (
    select *
    from Teacher
    group by teacher_id, subject_id
) a
group by teacher_id