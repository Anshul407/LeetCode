WITH b AS (
    SELECT product_id, MIN(year) AS year
    FROM sales
    GROUP BY product_id
)
SELECT product_id,year as first_year,quantity,price  
FROM sales
WHERE (product_id, year) IN (SELECT product_id, year FROM b);
