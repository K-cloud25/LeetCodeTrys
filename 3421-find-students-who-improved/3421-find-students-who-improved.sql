WITH ma AS (SELECT student_id, subject,score
FROM Scores 
WHERE (student_id, subject, exam_date) IN (SELECT student_id, subject ,MAX(exam_date)
FROM Scores
GROUP BY student_id, subject))
, mi AS (SELECT student_id, subject,score
FROM Scores 
WHERE (student_id, subject, exam_date) IN (SELECT student_id, subject ,MIN(exam_date)
FROM Scores
GROUP BY student_id, subject))
SELECT mi.student_id, mi.subject, mi.score AS first_score, ma.score AS latest_score
FROM ma AS ma
LEFT JOIN mi AS mi
ON mi.student_id = ma.student_id AND mi.subject=ma.subject
WHERE ma.score - mi.score >0
ORDER BY mi.student_id, mi.subject