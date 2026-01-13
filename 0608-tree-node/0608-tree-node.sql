WITH par AS (SELECT DISTINCT p_id
FROM Tree
WHERE p_id IS NOT NULL)
SELECT id, 
    CASE   
        WHEN (t.p_id IS NULL) AND (p.p_id IS NOT NULL) THEN 'Root'
        WHEN (t.p_id IS NOT NULL) AND (p.p_id IS NOT NULL) THEN 'Inner'
        WHEN (t.p_id IS NOT NULL) AND (p.p_id IS NULL) THEN 'Leaf'
        ELSE 'Root'
    END AS type
FROM Tree AS t
LEFT JOIN par AS p
ON p.p_id = t.id
