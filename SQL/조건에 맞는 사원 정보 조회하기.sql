-- 2022년도 한해 평가 점수 가장 높은 사원 정보 조회 
-- 2022년도 평가 점수 가장 높은 사원들의 점수, 사번, 성명, 직책, 이메일 조회 핡 ㅓㅅ 
-- 평가점수 : 상,하반기 점수의 합 

SELECT E_TOTAL.TOTAL_SCORE AS SCORE, E.EMP_NO, E.EMP_NAME, E.POSITION, E.EMAIL
FROM HR_EMPLOYEES E
JOIN (SELECT EMP_NO, SUM(SCORE) AS TOTAL_SCORE 
      FROM HR_GRADE
      GROUP BY EMP_NO) AS E_TOTAL
ON E.EMP_NO = E_TOTAL.EMP_NO
ORDER BY E_TOTAL.TOTAL_SCORE DESC
LIMIT 1