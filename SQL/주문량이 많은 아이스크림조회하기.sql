-- 7월 아이스크림 총 주문량과 상반기의 아이스크림 총 주문량을 더한 값이 큰 순서대로 상위3개의 맛을 조회 

-- # SELECT * FROM FIRST_HALF; -- SHIPMENT_ID, FLAVOR, TOTLAL_ORDER
-- # SELECT * FROM JULY; -- SHIPMENT_ID, FLAVOR, TOTAL_ORDER

-- # SELECT J.FLAVOR
-- # FROM FIRST_HALF H
-- # WHERE (
       
-- -- ver1. 
-- -- 이렇게하니 group by 를 수행하지 못해서 잘못된 결과가 나왔다. 
-- # SELECT S.TOTAL, S.FLAVOR
-- # FROM (SELECT H.SHIPMENT_ID, H.FLAVOR, (SUM(H.TOTAL_ORDER) + SUM(J.TOTAL_ORDER)) AS TOTAL
-- #     FROM FIRST_HALF H, JULY J
-- #     WHERE H.SHIPMENT_ID = J.SHIPMENT_ID
-- #     GROUP BY H.FLAVOR, J.FLAVOR
-- #     ORDER BY TOTAL DESC) S
-- # LIMIT 3;


-- 알게된 사실 ! 
-- mysql에서는 full outer join을 지원하지 않는다 
-- 양쪽에서 모두 필요할 때는 union all 을 사용하고 group by 를 돌리자 

SELECT FLAVOR
FROM(SELECT H.FLAVOR, SUM(H.TOTAL_ORDER) AS TOTAL
      FROM FIRST_HALF H
      GROUP BY FLAVOR
      UNION ALL
      SELECT J.FLAVOR,SUM(J.TOTAL_ORDER) AS TOTAL
      FROM JULY J
      GROUP BY FLAVOR) AS T
GROUP BY T.FLAVOR
ORDER BY SUM(T.TOTAL) DESC
LIMIT 3
      


