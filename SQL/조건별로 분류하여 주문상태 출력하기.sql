-- 2022년 5월 1일 기준으로 주문 ID, 제품 ID, 출고일자, 출고여부 조회 
-- 2022년 5월 1일까지 출고완료로 -> 이 후 날짜는 출고대ㅣ / 미정이면 출고미정 
-- order by 주문 ID 

SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE, "%Y-%m-%d") AS OUT_DATE,
        (CASE WHEN OUT_DATE IS NULL THEN'출고미정'
              WHEN MONTH(OUT_DATE) < 5 || OUT_DATE LIKE "2022-05-01" THEN '출고완료'
              ELSE '출고대기' END) AS '출고여부'
FROM FOOD_ORDER
ORDER BY ORDER_ID;