-- 대여 시작일 기준으로 2022년 8월부터 2022년 10월까지 
-- 총 대여횟수가 5회 이상인 자동차들에 대해 
-- 해당 기간 동안의 월별 자동차 ID 별 총 대여횟수 (as RECORDS)
-- 월 asc, 자동차 id desc 
-- WHERE START_DATE >= '2022-08-01' AND START_DATE <= '2022-10-31'

-- where 절의 날짜 조건은 서브쿼리, 본 쿼리 둘 다에 들어가야된다. 서브쿼리에만 들어가게되면, 
-- H랑 조인하게 되면서 데이터가 엉망이 되어버림 

SELECT MONTH(H.START_DATE) AS MONTH, H.CAR_ID, COUNT(H.HISTORY_ID) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H,
        (SELECT CAR_ID, HISTORY_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE START_DATE >= '2022-08-01' AND START_DATE <= '2022-10-31'
        GROUP BY CAR_ID
        HAVING COUNT(HISTORY_ID) >= 5) AS C
WHERE H.CAR_ID = C.CAR_ID AND START_DATE >= '2022-08-01' AND START_DATE <= '2022-10-31'
GROUP BY MONTH(START_DATE), C.CAR_ID
ORDER BY 1 ASC, 2 DESC 

                 


