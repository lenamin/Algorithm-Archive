
-- 묵시적 조인 

SELECT B.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, SUM(B.PRICE * S.SALES) AS TOTAL_SALES
FROM BOOK B, AUTHOR A, (SELECT BOOK_ID, SALES
                        FROM BOOK_SALES B
                        WHERE SALES_DATE <= '2022-01-31') AS S
WHERE B.BOOK_ID = S.BOOK_ID AND B.AUTHOR_ID = A.AUTHOR_ID
GROUP BY B.CATEGORY, B.AUTHOR_ID
ORDER BY 1, 3 DESC;



-- 명시적 조인을 사용할 것 
SELECT B.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, SUM(B.PRICE * S.SALES) AS TOTAL_SALES
FROM BOOK B
JOIN AUTHOR A ON B.AUTHOR_ID = A.AUTHOR_ID
JOIN (SELECT BOOK_ID, SALES
      FROM BOOK_SALES B
      WHERE SALES_DATE <= '2022-01-31') AS S ON S.BOOK_ID = B.BOOK_ID
GROUP BY B.CATEGORY, B.AUTHOR_ID
ORDER BY 1, 3 DESC;