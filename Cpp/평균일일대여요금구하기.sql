-- 평균 일일 대여 요금 구하기 문제 (프로그래머스)

-- 자동차 종류가 SUV인 자동차들의 평균 일일 대여 요금 출력

SELECT ROUND(AVG(DAILY_FEE)) AS AVERAGE_FEE
FROM CAR_RENTAL_COMPANY_CAR
WHERE CAR_TYPE = 'SUV';