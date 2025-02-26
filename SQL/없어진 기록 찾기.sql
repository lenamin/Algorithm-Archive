-- 입양을 간 기록은 있는데 (OUT), 보호소에 들어온 기록이 없으면 (IN) 
-- 그 동물의 ANIMAL_ID, NAME 조회 
-- ID 순으로 

SELECT O.ANIMAL_ID, O.NAME
FROM ANIMAL_OUTS O
LEFT OUTER JOIN ANIMAL_INS I
ON O.ANIMAL_ID = I.ANIMAL_ID
WHERE I.ANIMAL_ID IS NULL
ORDER BY O.ANIMAL_ID;