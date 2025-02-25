-- 12세 이하인 여자환자 
-- 환자이름, 환자번호, 성별코드, 나이, 전화번호 (없는 경우 NONE) 
-- 나이기준 내림차순 / 나이같으면 환자이름으로 오름차순 

SELECT PT_NAME, PT_NO, GEND_CD, AGE, COALESCE(TLNO, 'NONE')
FROM PATIENT
WHERE AGE <= 12 AND GEND_CD = 'W'
ORDER BY AGE DESC, PT_NAME ASC