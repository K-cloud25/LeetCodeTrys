WITH cte AS (SELECT t1.client_id, t1.driver_id, t1.request_at, t1.status,  
COUNT(1) OVER(PARTITION BY request_at) AS cnt
FROM Trips AS t1
LEFT JOIN Users AS c
ON c.users_id = t1.client_id AND c.role = 'client'
LEFT JOIN Users AS d 
ON d.users_id = t1.driver_id AND d.role = 'driver'
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03' AND c.banned <> 'Yes' AND d.banned <> 'Yes')
SELECT 
    request_at AS Day,
    ROUND(SUM(CASE WHEN (status LIKE 'cancelled%' ) THEN 1 ELSE 0 END) / cnt,2) AS 'Cancellation Rate' 
FROM cte 
GROUP BY request_at