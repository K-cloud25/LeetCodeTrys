SELECT customer_id
FROM Customer C
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(DISTINCT product_key) AS cnt FROM Product)