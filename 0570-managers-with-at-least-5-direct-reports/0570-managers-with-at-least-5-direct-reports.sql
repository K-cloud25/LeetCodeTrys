# Write your MySQL query statement below
WITH cte AS (SELECT managerId,COUNT(managerId) AS cnt
FROM Employee
GROUP BY managerId
HAVING cnt>=5)
SELECT name
FROM Employee AS E
LEFT JOIN cte AS c ON c.managerId = E.id
WHERE cnt>=5