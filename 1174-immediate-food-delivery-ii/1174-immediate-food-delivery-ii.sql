SELECT 
    ROUND( SUM( CASE WHEN DATEDIFF(order_date,customer_pref_delivery_date)=0 THEN 1 ELSE 0 END ) * 100/ count(*) ,2) AS immediate_percentage
FROM (
SELECT customer_id, order_date,customer_pref_delivery_date, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS rnt
FROM Delivery
) AS t
WHERE rnt=1
