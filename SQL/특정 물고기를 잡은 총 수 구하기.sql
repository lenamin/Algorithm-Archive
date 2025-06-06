-- BASS와 SNAPPER 수 출력 

SELECT SUM(TYPE.C) AS FISH_COUNT
FROM (SELECT COUNT(N.FISH_TYPE) AS C
       FROM FISH_NAME_INFO N, FISH_INFO F
       WHERE (N.FISH_TYPE = F.FISH_TYPE) AND N.FISH_NAME IN ('BASS', 'SNAPPER')
       GROUP BY N.FISH_TYPE) AS TYPE

