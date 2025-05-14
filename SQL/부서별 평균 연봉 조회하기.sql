-- 부서별 평균 연봉 조회하기 
-- 부서별 부서 ID, 영문명, 평균 연봉 조회 
-- 평균연봉 : 소수점 첫째 자리에서 반올림 / 컬럼명 : AVG_SAL 
-- order by AVG_SAL 

SELECT E.DEPT_ID, D.DEPT_NAME_EN, E.AVG_SAL
FROM HR_DEPARTMENT D
JOIN (SELECT DEPT_ID, ROUND(AVG(SAL), 0) AS AVG_SAL
      FROM HR_EMPLOYEES
      GROUP BY DEPT_ID) E
ON E.DEPT_ID = D.DEPT_ID
ORDER BY 3 DESC