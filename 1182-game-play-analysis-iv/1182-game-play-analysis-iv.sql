WITH firstLogin AS (
    SELECT 
        player_id,
        event_date,
        ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY event_date) AS rn
    FROM Activity
)
SELECT 
    ROUND(
        1.0 * COUNT(DISTINCT CASE 
                    WHEN a.event_date = DATE_ADD(fl.event_date, INTERVAL 1 DAY) THEN fl.player_id 
                    ELSE NULL 
                END)
        / COUNT(DISTINCT fl.player_id),
        2
    ) AS fraction
    FROM firstLogin fl
LEFT JOIN Activity a ON fl.player_id = a.player_id
WHERE fl.rn = 1;
