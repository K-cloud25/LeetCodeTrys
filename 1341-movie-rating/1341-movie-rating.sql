(SELECT U.name AS results
FROM MovieRating AS M
LEFT JOIN Users AS U
ON U.user_id = M.user_id
GROUP BY M.user_id
ORDER BY COUNT(*) DESC, name
LIMIT 1)
UNION ALL
(SELECT M.title AS results
FROM MovieRating AS MR
LEFT JOIN Movies AS M
ON M.movie_id = MR.movie_id
WHERE EXTRACT(YEAR_MONTH FROM MR.created_at) = 202002
GROUP BY M.movie_id
ORDER BY  AVG(MR.rating) DESC, M.title
LIMIT 1) 