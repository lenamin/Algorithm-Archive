-- 음식종류별로 즐겨찾기수가 가장 많은 식당의 음식 종류, ID, 식당 이름, 즐겨찾기수를 조회
-- order by 음식종류 desc

SELECT R.FOOD_TYPE, R.REST_ID, R.REST_NAME, F.FAV AS FAVORITES
FROM REST_INFO R
JOIN (SELECT FOOD_TYPE, MAX(FAVORITES) AS FAV
      FROM REST_INFO
      GROUP BY FOOD_TYPE) AS F
ON F.FAV = R.FAVORITES AND F.FOOD_TYPE = R.FOOD_TYPE
ORDER BY FOOD_TYPE DESC
