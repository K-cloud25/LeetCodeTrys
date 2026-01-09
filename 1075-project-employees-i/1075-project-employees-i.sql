# Write your MySQL query statement below
SELECT project_id, ROUND(AVG(E.experience_years),2) as average_years
FROM Project as P
LEFT JOIN Employee as E ON E.employee_id = P.employee_id
GROUP BY P.project_id