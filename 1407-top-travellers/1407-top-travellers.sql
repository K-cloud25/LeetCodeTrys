# Write your MySQL query statement below
SELECT U.name, SUM(COALESCE(distance,0)) AS travelled_distance
FROM Users AS U
LEFT JOIN Rides AS R
ON R.user_id = U.id
GROUP BY (U.id)
ORDER BY travelled_distance DESC, name