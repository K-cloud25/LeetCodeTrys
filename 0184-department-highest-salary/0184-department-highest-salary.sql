WITH cte AS(SELECT d.id, MAX(e.salary) as m, d.name
FROM Employee AS e
LEFT JOIN Department AS d
ON d.id = e.departmentId
GROUP BY e.departmentId)
SELECT c.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee AS e
LEFT JOIN cte AS c
ON c.id = e.departmentId 
WHERE c.m = e.salary