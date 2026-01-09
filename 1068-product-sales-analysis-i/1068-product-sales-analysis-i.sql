# Write your MySQL query statement below
SELECT P.product_name, S.year, S.price
FROM Product as P
LEFT JOIN Sales as S ON S.product_id = P.product_id
WHERE S.year IS NOT NULL AND S.price IS NOT NULL