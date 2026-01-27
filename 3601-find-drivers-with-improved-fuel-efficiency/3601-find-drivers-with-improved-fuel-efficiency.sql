WITH cte AS (SELECT driver_id, 
CASE WHEN MONTH(trip_date) BETWEEN 1 AND 6 THEN true ELSE false END AS first_half, 
AVG(distance_km/fuel_consumed)AS fuel
FROM Trips
GROUP BY driver_id, first_half)
SELECT 
    D.driver_id, 
    D.driver_name, 
    ROUND(cte1.fuel,2) AS first_half_avg, 
    ROUND(cte2.fuel,2) AS second_half_avg,
    ROUND(cte2.fuel-cte1.fuel,2) AS efficiency_improvement 
FROM cte AS cte1
JOIN cte AS cte2
ON cte1.driver_id = cte2.driver_id
JOIN drivers AS D
ON D.driver_id = cte1.driver_id
WHERE 
    cte1.first_half = 1 AND cte2.first_half=0 
    AND cte1.fuel<cte2.fuel
ORDER BY efficiency_improvement DESC, D.driver_name