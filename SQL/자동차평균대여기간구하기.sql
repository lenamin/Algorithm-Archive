-- SELECT * FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY;

-- 평균 대여기간이 7일 이상인 자동차들의 자동차 ID,평균대여기간 (AVERAGE_DURATION)  - 소수 두 번째 자리에서 반올림 / 평균대여기간 기준 내림차순 / /자동차ID 기준 내림차수 ㄴ

SELECT CAR_ID, ROUND(AVG(DATEDIFF(END_DATE, START_DATE) + 1), 1) AS AVERAGE_DURATION
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
HAVING AVERAGE_DURATION >= 7
ORDER BY 2 DESC, 1 DESC;

-- 1. 
    -- END_DATE - START_DATE + 1로 계산하면 옳지 않은 수를 반환함. 
    -- 만약 이렇게 하고싶다면 DATE(END_DATE) - DATE(START_DATE) + 1 이런식으로 해야 정수값을 반환하도록 강제할 수 있음. 
    -- 그래도 그냥 DATEDIFF 쓰는게 제일 안전하겠다 

-- 2. 
    -- 힘들게 서브쿼리에서 평균값을 계산하지 않아도 됨 
    -- group by의 having 절에서 average_duration조건을 주면 되잖아... 너무 어렵게 생각했음. 