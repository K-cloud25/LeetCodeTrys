# Write your MySQL query statement below
WITH cte AS ( SELECT product_id, MIN(year) AS year FROM Sales GROUP BY product_id )
SELECT S.product_id, S.year AS first_year, S.quantity, S.price
FROM Sales AS S
LEFT JOIN cte ON cte.product_id =S.product_id AND cte.year = S.year
WHERE cte.year IS NOT NULL