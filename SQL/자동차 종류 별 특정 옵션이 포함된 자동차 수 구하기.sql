SELECT C.CAR_TYPE, COUNT(C.CAR_ID) AS CARS
FROM CAR_RENTAL_COMPANY_CAR C, (SELECT CAR_ID, CAR_TYPE
                                FROM CAR_RENTAL_COMPANY_CAR 
                                WHERE OPTIONS LIKE '%통풍시트%' 
                                     OR OPTIONS LIKE '%열선시트%' 
                                     OR OPTIONS LIKE '%가죽시트%') AS O
WHERE C.CAR_ID = O.CAR_ID
GROUP BY C.CAR_TYPE
ORDER BY 1;