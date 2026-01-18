WITH cte AS (SELECT user_id, ROUND(SUM(CASE WHEN action='confirmed' THEN 1 ELSE 0 END) / COUNT(1), 2) AS confirmation_rate
FROM Confirmations
GROUP BY user_id)
SELECT S.user_id, COALESCE(C.confirmation_rate, 0) AS confirmation_rate
FROM Signups AS S
LEFT JOIN cte AS C
ON C.user_id = S.user_id