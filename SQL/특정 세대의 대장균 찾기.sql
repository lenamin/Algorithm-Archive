WITH CHILDS AS (
    SELECT E2.ID AS ID
    FROM ECOLI_DATA E1
    JOIN ECOLI_DATA E2
    ON E1.ID = E2.PARENT_ID
     WHERE E1.PARENT_ID IS NULL
)
SELECT E3.ID AS ID
FROM CHILDS C
JOIN ECOLI_DATA E3
ON C.ID = E3.PARENT_ID
ORDER BY 1