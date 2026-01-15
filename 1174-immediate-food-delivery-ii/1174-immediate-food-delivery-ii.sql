SELECT ROUND((SUM( 
    CASE WHEN DATEDIFF(order_date, customer_pref_delivery_date) = 0
    THEN 1
    ELSE 0
    END
 ) / COUNT(DISTINCT customer_id))*100, 2 )AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN (    SELECT customer_id, MIN(order_date)
    FROM Delivery
    GROUP BY customer_id)