# Write your MySQL query statement below
select x,y,z, (
    case when (x < y + z and y < x + z and z < x + y) then 'Yes' else 'No' end
) as triangle
from Triangle
