-- FOOD_PRODUCT 테이블에서 
-- 식품분류별로 가격이 제일 비싼 식품의
-- 분류, 가격, 이름 조회 
-- 식품분류 = 과자, 국, 김치, 식용유인 경우만 출력 
-- order by 식품가격 desc 

SELECT C.CATEGORY, C.MAX_PRICE, P.PRODUCT_NAME
FROM FOOD_PRODUCT P
JOIN (SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE
      FROM FOOD_PRODUCT
      WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
      GROUP BY CATEGORY
      ORDER BY 2 DESC) AS C 
ON C.CATEGORY = P.CATEGORY AND C.MAX_PRICE = P.PRICE
ORDER BY 2 DESC;

-- GROUP BY로 최대값을 구한 후, 해당 값을 만족하는 행의 다른 컬럼을 추출하려면, 서브쿼리와 조인을 사용해 조건 매칭해야 한다.
                    
