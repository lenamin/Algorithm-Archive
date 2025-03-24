-- INS 중에서 이름이 Lucy, Ella, Pickle, Rogan, Sabrina, Mitty인 동물의 아이디, 이름, 성별, 중성화여부 
-- 아이디 순 
SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME = "Lucy" || NAME = "Ella" || NAME = "Pickle" || NAME = "Rogan" || NAME = "Sabrina" || NAME = "Mitty"
ORDER BY ANIMAL_ID