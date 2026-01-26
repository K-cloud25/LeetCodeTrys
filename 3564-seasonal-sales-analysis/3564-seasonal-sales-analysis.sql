WITH cte AS (SELECT
    CASE 
        WHEN (MONTH(S.sale_date) IN (12, 1, 2) ) THEN 'Winter'
        WHEN (MONTH(S.sale_date) IN (3, 4, 5)) THEN 'Spring'
        WHEN (MONTH(S.sale_date) IN (6, 7, 8)) THEN 'Summer'
        WHEN (MONTH(S.sale_date) IN (9,10, 11)) THEN 'Fall'
    END AS season,
    P.category,
    ROUND(SUM(S.price * S.quantity),2) AS total_revenue,
    SUM(S.quantity) AS total_quantity
FROM Sales AS S 
LEFT JOIN Products AS P
ON P.product_id = S.product_id
GROUP BY P.category, season)
, 
rank_cte AS (
    SELECT 
        season,
        category,
        total_quantity,
        total_revenue,
        RANK() OVER (PARTITION BY season ORDER BY total_quantity DESC, total_revenue DESC ) as rnk
    FROM cte
)
SELECT season, category,total_quantity, total_revenue
FROM rank_cte
WHERE rnk=1
ORDER BY season