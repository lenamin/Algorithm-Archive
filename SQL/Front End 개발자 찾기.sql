-- FrontEnd 개발자 찾기
-- DEVELOPERS 테이블에서 
-- FRONT END 스킬 가진 개발자 정보 조회 
-- 개발자 ID, 이메일, 성 조회할 것 


SELECT D.ID, D.EMAIL, D.FIRST_NAME, D.LAST_NAME
FROM DEVELOPERS D
WHERE EXISTS (SELECT 1
                 FROM SKILLCODES S
                 WHERE S.CATEGORY = 'Front End' AND (D.SKILL_CODE & S.CODE > 0))
ORDER BY D.ID ASC;

-- 실수했던 부분 
-- 처음에 문제 이해를 제대로 못해서 D.SKILL_CODE = S.CODE 의 형식으로 서브쿼리를 줬더니 오답이 나왔다. 
-- 문제를 꼼꼼하게 읽자 
-- 비트마스킹 이용해서 푼 문제 