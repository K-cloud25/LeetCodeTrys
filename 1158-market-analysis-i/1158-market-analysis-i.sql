WITH cte AS (SELECT buyer_id,COUNT(1) AS cnt
FROM Orders
WHERE YEAR(order_date) = 2019
GROUP BY buyer_id)
SELECT u.user_id AS buyer_id, u.join_date, COALESCE(c.cnt,0) AS orders_in_2019
FROM Users AS u
LEFT JOIN cte AS c
ON c.buyer_id = u.user_id 