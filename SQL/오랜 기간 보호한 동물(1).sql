-- 아직 입양 못간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 NAME, 보호시작일 (DATETIME), 
-- order by 보호시작일 순 asc 

-- 특정 개수의 데이터만 출력하고 싶을 때 -> LIMIT 개수

SELECT I.NAME, I.DATETIME
FROM ANIMAL_INS I
LEFT OUTER JOIN ANIMAL_OUTS O
ON O.ANIMAL_ID = I.ANIMAL_ID 
WHERE O.ANIMAL_ID IS NULL
ORDER BY I.DATETIME ASC
LIMIT 3;
