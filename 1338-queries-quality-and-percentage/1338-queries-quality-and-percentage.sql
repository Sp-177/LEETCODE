SELECT 
    q.query_name,
    ROUND(
        IFNULL(SUM(q.rating / q.position) / NULLIF(COUNT(*), 0), 0),
        2
    ) AS quality,
    ROUND(
        (COUNT(CASE WHEN q.rating < 3 THEN 1 END) * 100.0) / NULLIF(COUNT(*), 0),
        2
    ) AS poor_query_percentage
FROM Queries q
GROUP BY q.query_name;
