# Write your MySQL query statement below
SELECT 
    'Low Salary' AS category,
    COUNT(1) AS accounts_count
FROM accounts
WHERE income < 20000
UNION 
SELECT
    'Average Salary' AS category,
    COUNT(1) AS accounts_count
FROM accounts
WHERE income >= 20000 AND income <= 50000
UNION
SELECT
    'High Salary' AS category,
    COUNT(1) AS accounts_count
FROM accounts
WHERE income > 50000