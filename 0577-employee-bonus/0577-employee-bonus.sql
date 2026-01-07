# Write your MySQL query statement below
SELECT e.name, s.bonus
FROM Employee as e
LEFT JOIN Bonus as s 
ON s.empId=e.empId
WHERE s.bonus IS NULL OR s.bonus<1000;