-- 강원도에 위치한 식품공장의 공장ID, 공장이름, 주소 조회
SELECT FACTORY_ID, FACTORY_NAME, ADDRESS
FROM FOOD_FACTORY
WHERE ADDRESS LIKE '강원도%';