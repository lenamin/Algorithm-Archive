-- 사번 EMP_NO, 성명 EMP_NAME, 평가등급 GRADE, 성과금 조회 BONUS
-- order by dept_id

-- HR_DEPARTMENT : 팀 아이디, 팀 이름, 팀 이름 영어, 장소
-- HR_EMPLOYEES : 사번, 이름, 팀이름, 직급, 이메일, 내선번호, 연봉 (SAL)
-- HR_GRADE : 사번, 연도, 반기 (1/2), 점수 SCORE 

-- # EMP_NO EMP_NAME GRADE
-- # 2017002	정호식	 A
-- # 2017002	정호식	 B
-- # 2018001	김민석	 B
-- # 2018001	김민석	 B

WITH GRADES AS (
    SELECT E.EMP_NO, E.EMP_NAME, 
           (CASE 
                WHEN SUM(G.SCORE)/2 >= 96 THEN 'S' 
                WHEN SUM(G.SCORE)/2 >= 90 THEN 'A'
                WHEN SUM(G.SCORE)/2 >= 80 THEN 'B'
                ELSE 'C' 
            END) AS GRADE
    FROM HR_EMPLOYEES AS E
    JOIN HR_GRADE AS G
    ON E.EMP_NO = G.EMP_NO
    GROUP BY E.EMP_NO, E.EMP_NAME
)
SELECT E2.EMP_NO, E2.EMP_NAME, G2.GRADE, 
       (CASE 
            WHEN G2.GRADE = 'S' THEN E2.SAL * 0.2
            WHEN G2.GRADE = 'A' THEN E2.SAL * 0.15
            WHEN G2.GRADE = 'B' THEN E2.SAL * 0.1
        ELSE 0 
        END) AS BONUS
FROM GRADES AS G2
JOIN HR_EMPLOYEES AS E2
ON G2.EMP_NO = E2.EMP_NO
ORDER BY E2.EMP_NO