WITH ReactionStats AS
(
    SELECT user_id, reaction AS dominant_reaction,
        COUNT(DISTINCT content_id) AS reaction_count,
        SUM(COUNT(DISTINCT content_id)) OVER(PARTITION BY user_id) AS total_count
    FROM reactions
    GROUP BY user_id, reaction)
SELECT user_id, dominant_reaction,
    round((reaction_count * 1.0) / total_count, 2) AS reaction_ratio
FROM ReactionStats
WHERE total_count >= 5
and (reaction_count * 1.0) / total_count > 0.6
ORDER BY reaction_ratio DESC, user_id;