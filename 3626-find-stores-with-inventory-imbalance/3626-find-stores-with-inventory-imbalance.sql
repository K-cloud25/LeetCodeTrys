WITH ma AS (SELECT 
    i.store_id, 
    i.product_name,
    i.quantity,
    i.price,
    RANK() OVER( PARTITION BY i.store_id ORDER BY price DESC, quantity DESC ) AS rnk,
    COUNT(*) OVER(PARTITION BY i.store_id) AS cnt
FROM inventory AS i),
mi AS (SELECT 
    i.store_id, 
    i.product_name,
    i.quantity,
    i.price,
    RANK() OVER( PARTITION BY i.store_id ORDER BY price, quantity ) AS rnk,
    COUNT(*) OVER(PARTITION BY i.store_id) AS cnt
FROM inventory AS i)
SELECT
    ma.store_id, 
    s.store_name,
    s.location,
    ma.product_name AS most_exp_product,
    mi.product_name AS cheapest_product,
    ROUND(mi.quantity/ma.quantity, 2) AS imbalance_ratio
FROM ma AS ma
LEFT JOIN stores AS s
ON s.store_id = ma.store_id
LEFT JOIN mi AS mi
ON ma.store_id = mi.store_id
WHERE ma.rnk = 1 AND mi.rnk=1 AND ma.quantity < mi.quantity AND mi.cnt >= 3
ORDER BY imbalance_ratio DESC, s.store_name 