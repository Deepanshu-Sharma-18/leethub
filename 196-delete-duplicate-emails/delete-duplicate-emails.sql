# Write your MySQL query statement below
DELETE FROM Person
WHERE id NOT IN (
    SELECT min_id
    FROM (
        SELECT MIN(id) AS min_id
        FROM Person
        GROUP BY email
    ) AS subquery
);