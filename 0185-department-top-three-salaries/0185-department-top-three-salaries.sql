WITH cte AS (SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary,
    DENSE_RANK() OVER(PARTITION BY d.name ORDER BY salary DESC) AS rnk
FROM Employee AS e
LEFT JOIN Department AS d
ON d.id = e.departmentId)
SELECT Department, Employee, Salary
FROM cte
WHERE rnk BETWEEN 1 AND 3