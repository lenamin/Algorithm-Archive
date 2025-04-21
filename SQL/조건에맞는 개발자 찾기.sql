-- Python, C# 스킬 가진 개발자의 정보 조회
-- 개발자 ID, 이메일, 성 조회 
-- order by ID asc

SELECT D.ID, D.EMAIL, D.FIRST_NAME, D.LAST_NAME
FROM DEVELOPERS D
WHERE D.SKILL_CODE & (SELECT SUM(CODE)
                      FROM SKILLCODES
                      WHERE NAME IN ('Python', 'C#')) > 0
ORDER BY D.ID ASC;
