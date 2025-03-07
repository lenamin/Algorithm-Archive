-- 보호소에 들어올 당시에는 중성화 X 
-- but 보호소에서 나갈 땐 중성화가 되어있는 
-- 동물 아이디, 새물종, 이름 
-- order by 아이디 순 

-- 중성화 안한 동물 : Intact 
-- 중성화 한 동물 Spayed or Neutered 


-- 우선 보호소에 들어올 때 중성화 안된 애들부터 조회하자 
-- # (SELECT *
-- # FROM ANIMAL_INS I
-- # WHERE SEX_UPON_INTAKE LIKE "Intact%") AS I_INT

-- 얘네들 중에서 나가는 애랑 조인한 다음에, SEX_UPON_OUTCOME 이 SPAYED 나 NEUTERED 로 시작하는 거 있으면 출력하는 걸로 

-- 실수했던 부분 : 
    -- AND 연산자는 OR 연산자보다 우선순위가 높기 때문에 
    -- WHERE O.ANIMAL_ID = I_INT.ANIMAL_ID AND (O.SEX_UPON_OUTCOME LIKE "Spayed%" OR O.SEX_UPON_OUTCOME LIKE "Neut%"
    -- 이렇게 괄호로 우선순위를 명확하게 해주지 않으면 조인조건과 Spayed 인 동시조건 OR Neut 인 것 이런식으로 작동해서 올바르지 않은 결과가 나온 것! 
    


SELECT O.ANIMAL_ID, O.ANIMAL_TYPE, O.NAME
FROM ANIMAL_OUTS O, (SELECT *
                    FROM ANIMAL_INS I
                    WHERE SEX_UPON_INTAKE LIKE "Intact%") AS I_INT
WHERE (O.ANIMAL_ID = I_INT.ANIMAL_ID)
      AND (O.SEX_UPON_OUTCOME LIKE "Spayed%" OR O.SEX_UPON_OUTCOME LIKE "Neut%")
ORDER BY O.ANIMAL_ID
