SELECT 
    s.user_id,
    ROUND(
        IFNULL(confirmed.count, 0) / IFNULL(total.count, 1),
        2
    ) AS confirmation_rate
FROM Signups s
LEFT JOIN (
    SELECT user_id, COUNT(*) AS count
    FROM Confirmations
    GROUP BY user_id
) AS total ON s.user_id = total.user_id
LEFT JOIN (
    SELECT user_id, COUNT(*) AS count
    FROM Confirmations
    WHERE action = 'confirmed'
    GROUP BY user_id
) AS confirmed ON s.user_id = confirmed.user_id;
