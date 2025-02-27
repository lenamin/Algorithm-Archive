# SELECT * FROM CAR_RENTAL_COMPANY_CAR -- CAR_ID (디스카운트의 외래키), CAR_TYPE, DAILY_FEE, OPTIONS
# SELECT * FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY -- HISTORY_ID, CAR_ID (외래키), START_DATE, END_DATE
# SELECT * FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN -- PLAN_ID, CAR_TYPE , DURATION_TYPE, DISCOUNT_RATE

-- 할인율이 적용되는 대여기간 종류 : 7일 이상 ( 7 <= 대여기간 < 30일), 30일 이상 (30 <= 대여기간 < 90), 90일 이상 ( 90 <= 대여기간) 
-- 대여기간 7일미만 -> 할인 X

-- 세단, SUV 자동차 중에서 
-- 2022년 11월 1일 ~ 2022년 11월 30일 대여가능 
-- 50 <= 30일 간의 대여 금액이 < 200 
-- 자동차 ID, 자동차 종류, 대여금액 (as fee) 
-- 대여금액 desc, 자동차종류 asc, 자동차ID desc

-- 실수 1. DATE_FORMAT(H.START_DATE, '%M') != '11' 로 하면 November로 되어서 정확한 비교가 힘듦 -> MONTH() 를 사용해야 함 
-- 실수 2. 위 조건처럼 검색하면 시작일이 11월 전이고, 끝날이 12월 이상일 때를 잡지 못함. 11월 범위를 잡고 NOT IN 으로 했어야 했다 

SELECT C.CAR_ID, C.CAR_TYPE, ROUND(C.DAILY_FEE * 30 * (100 - P.DISCOUNT_RATE) / 100) AS FEE
FROM CAR_RENTAL_COMPANY_CAR C
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN P
ON C.CAR_TYPE = P.CAR_TYPE
    AND P.DURATION_TYPE = '30일 이상'
WHERE 1=1
    AND C.CAR_TYPE IN ('세단', 'SUV')
    AND C.CAR_ID NOT IN (SELECT CAR_ID
                        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                        WHERE START_DATE <= '2022-11-30' AND END_DATE >= '2022-11-01')
HAVING FEE >= 500000 AND FEE < 2000000
ORDER BY FEE DESC, C.CAR_TYPE ASC, C.CAR_ID DESC;