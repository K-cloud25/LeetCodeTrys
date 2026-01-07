WITH q1 AS (
    SELECT 
        *,
        LAG(temperature) OVER (ORDER BY recordDate) AS prevTemp,
        LAG(recordDate) OVER (ORDER BY recordDate) AS prevDate
    FROM Weather
)
SELECT id 
FROM Q1 WHERE temperature>prevTemp AND DATEDIFF(recordDate, prevDate) = 1;