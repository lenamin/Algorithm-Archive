-- 2021년에 가입한 전체 회원들 중 
-- 상품을 구매한 회원수, 
-- 상품을 구매한 회원의 비율 (=2021년에 가입한 회원 중 상품을 구매한 회원수 / 2021년에 가입한 전체 회원 수)
-- -> 년, 월 별로 출력

-- ORDER BY 연도 기준으로 asc, month asc 

-- # SELECT * FROM USER_INFO; -- USER_ID, GENDER, AGE, JOINED (date)
-- # SELECT * FROM ONLINE_SALE; -- online_sale_id, user_id, product_id, sales_amount, sales_date


-- # SELECT YEAR(O.SALES_DATE) AS YEAR, 
-- #         MONTH(O.SALES_DATE) AS MONTH, 
-- #         COUNT(JOINED.USER_ID) AS PURCHASED_USERS, 
-- #         ROUND(COUNT(O.USER_ID) / COUNT(JOINED.USER_ID), 1) AS PURCHASED_RATIO
-- # FROM ONLINE_SALE O, 
-- #     (SELECT * FROM USER_INFO WHERE YEAR(JOINED) = 2021) AS JOINED
-- # WHERE O.USER_ID = JOINED.USER_ID
-- # GROUP BY YEAR, MONTH
-- # ORDER BY YEAR ASC, MONTH ASC;

-- -- 이게 2021년에 회원가입했고, 또 상품을 구매한 모든 회원의 리스틑이 ㅁ
-- -- 이제 이걸 SALES_DATE 를 group by 해서 정렬하면 될거야 

-- -- 엉망진창인 첫번째 코드 ㅠㅠ

-- # SELECT YEAR(S.SALES_DATE) AS YEAR, 
-- #         MONTH(S.SALES_DATE) AS MONTH, 
-- #         COUNT(S.USER_ID) AS PURCHASED_USERS, 
-- #         ROUND(COUNT(A.USER_ID) / COUNT(J.USER_ID), 1) AS PURCHASED_RATIO
-- # FROM ONLINE_SALE S, USER_INFO U, (SELECT DISTINCT J.USER_ID
-- #                                    FROM ONLINE_SALE O, (SELECT USER_ID, JOINED
-- #                                                       FROM USER_INFO 
-- #                                                       WHERE YEAR(JOINED) = 2021) AS J
-- #                                    WHERE O.USER_ID = J.USER_ID) AS A
-- # GROUP BY YEAR, MONTH
-- # ORDER BY 1, 2;


SELECT YEAR(S.SALES_DATE) AS YEAR, 
        MONTH(S.SALES_DATE) AS MONTH,
        COUNT(DISTINCT S.USER_ID) AS PURCHASED_USERS,
        ROUND(COUNT(DISTINCT S.USER_ID) / (SELECT COUNT(USER_ID) FROM USER_INFO WHERE YEAR(JOINED) = 2021), 1) AS PURCHASED_RATIO
FROM ONLINE_SALE S, (SELECT USER_ID FROM USER_INFO WHERE YEAR(JOINED) = 2021) AS A
WHERE S.USER_ID = A.USER_ID
GROUP BY YEAR, MONTH
ORDER BY 1, 2;

-- JOIN을 해버리게 되면 서브쿼리를 통해 만든 테이블 A는 이미 변경된 상태이다!! 
-- 그래서 2021년에 가입한 회원을 구할 때는 별도로 다시 서브쿼리를 써야 하는 것 
-- 이렇게 중복된 코드 안쓰는 방법 




SELECT 
    YEAR(S.SALES_DATE) AS YEAR, 
    MONTH(S.SALES_DATE) AS MONTH,
    COUNT(DISTINCT S.USER_ID) AS PURCHASED_USERS,
    ROUND(COUNT(DISTINCT S.USER_ID) / total_users.total_count, 1) AS PURCHASED_RATIO
FROM ONLINE_SALE S
JOIN (
    SELECT USER_ID, COUNT(*) OVER () AS total_count
    FROM USER_INFO 
    WHERE YEAR(JOINED) = 2021
) AS total_users
ON S.USER_ID = total_users.USER_ID
GROUP BY YEAR, MONTH, total_users.total_count
ORDER BY 1, 2;
    