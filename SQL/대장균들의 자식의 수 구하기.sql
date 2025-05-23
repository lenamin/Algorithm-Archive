-- 개장균 개체의 ID, 자식의 수 (CHILD_COUNT) 출력
-- 자식없으면 0으로 출력 
-- order by ID asc 

SELECT P.ID, COUNT(C.ID) AS CHILD_COUNT
FROM ECOLI_DATA P
LEFT JOIN ECOLI_DATA C
ON C.PARENT_ID = P.ID
GROUP BY P.ID
ORDER BY 1;