# Write your MySQL query statement below
WITH 
borrowed_books AS (
    SELECT * FROM borrowing_records WHERE return_date IS NULL
),
prefinal_version AS (
    SELECT 
    lb.book_id, lb.title, lb.author, lb.genre, lb.publication_year, 
    COUNT(bb.book_id) AS current_borrowers, lb.total_copies
    FROM library_books AS lb
    LEFT JOIN borrowed_books AS bb
    ON lb.book_id = bb.book_id
    GROUP BY lb.book_id
    HAVING (lb.total_copies - COUNT(bb.book_id)) = 0
)
SELECT pf.book_id, pf.title, pf.author, pf.genre, pf.publication_year, pf.current_borrowers FROM prefinal_version AS pf ORDER BY pf.current_borrowers DESC, pf.title ASC;