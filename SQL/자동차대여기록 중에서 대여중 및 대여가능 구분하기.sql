-- 2022년 10월 16일에 대여 중인 자동차면 '대여중'으로, 대여중이지 않으면 '대여가능' as AVAIABILITY
-- CAR_ID, AVAILABILITY 출력 
-- 자동차 ID desc 

SELECT CAR_ID, (CASE WHEN EXISTS (SELECT CAR_ID 
                                  FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY F
                                  WHERE START_DATE <= '2022-10-16' && END_DATE >= '2022-10-16' 
                                        AND F.CAR_ID = H.CAR_ID 
                                  GROUP BY CAR_ID)
                THEN '대여중' ELSE '대여 가능' END) AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
GROUP BY CAR_ID
ORDER BY 1 DESC;

-- 여기서 F.CAR_ID = H.CAR_ID  이 조건이 없으면 모두가 '대여중'으로 나온다 ! 
-- 