WITH RECURSIVE employee_levels AS (
    SELECT employee_id, 1 AS level
    FROM Employees
    WHERE manager_id IS NULL -- The CEO
    
    UNION ALL
    
    SELECT e.employee_id, el.level + 1
    FROM Employees e
    JOIN employee_levels el ON e.manager_id = el.employee_id
),

-- 2. Establish every direct and indirect reporting relationship
all_relationships AS (
    SELECT manager_id, employee_id AS subordinate_id
    FROM Employees
    WHERE manager_id IS NOT NULL
    
    UNION ALL
    
    SELECT ar.manager_id, e.employee_id AS subordinate_id
    FROM all_relationships ar
    JOIN Employees e ON ar.subordinate_id = e.manager_id
)
SELECT 
    e.employee_id,
    e.employee_name,
    el.level,
    COUNT(ar.subordinate_id) AS team_size,
    e.salary + COALESCE(SUM(s.salary), 0) AS budget
FROM Employees e
JOIN employee_levels el ON e.employee_id = el.employee_id
LEFT JOIN all_relationships ar ON e.employee_id = ar.manager_id
LEFT JOIN Employees s ON ar.subordinate_id = s.employee_id
GROUP BY e.employee_id, e.employee_name, el.level, e.salary
ORDER BY level ASC, budget DESC, employee_name ASC; 