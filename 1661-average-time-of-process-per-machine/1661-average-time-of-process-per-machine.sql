# Write your MySQL query statement below
with tab as (SELECT machine_id, process_id, SUM(
    CASE WHEN activity_type ='end' THEN timestamp
    WHEN activity_type = 'start' THEN timestamp*-1 END) as diff
FROM Activity
GROUP BY machine_id, process_id)
SELECT machine_id, ROUND(SUM( diff )/COUNT(*),3) as processing_time
FROM tab
GROUP BY machine_id