WITH cte AS 
(SELECT *, RANK() OVER(PARTITION BY employee_id ORDER BY review_date DESC) AS rnk
FROM performance_reviews AS P)
, temp AS (SELECT
    employee_id, 
    rating,
    LEAD(rating) OVER(PARTITION BY employee_id ORDER BY review_date DESC) AS rnk1, 
    LEAD(rating, 2) OVER(PARTITION BY employee_id ORDER BY review_date DESC ) AS rnk2
FROM cte
WHERE rnk IN ( 1,  2, 3) )
SELECT T.employee_id, E.name, (T.rating - T.rnk2) AS improvement_score
FROM temp AS T
LEFT JOIN employees AS E
ON E.employee_id = T.employee_id
WHERE T.rating>T.rnk1 AND T.rnk1 > T.rnk2
ORDER BY improvement_score DESC, E.name ASC