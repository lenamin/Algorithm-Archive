-- 그룹별 조건에 맞는 식당 목록 출력하기 
-- MEMBER_PROFILE
-- REST_REVIEW 

-- 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회 
-- select 회원 이름, 리뷰 텍스트, 리뷰 작성일 
-- order by 리뷰 작성일 asc, 리뷰 텍스트 asc 

-- MEMBER_ID 가 외래키가 되겠고 
-- REST_REVIEW 테이블에서 MEMBER_ID로 GROUP BY 했을 때 COUNT 가장 많은 사람이 작성한 전체 리뷰를 조회한다 
-- MEMBER_PROFILE은 이름 떄문에 필요함 
-- DATE 포맷 유의 

-- ver1 
-- count를 출력하려고 하니까 로직이 계속 꼬였다. 
--그게 아니라, 카운트한 결과를 토대로 세 개의 테이블로 조인을 하니까 문제가 풀렸다! 
-- # SELECT R.C, M.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, "%Y-%m-%d") AS REVIEW_DATE
-- # FROM (SELECT COUNT(REVIEW_ID) AS C, REST_ID, MEMBER_ID,  REVIEW_TEXT, REVIEW_DATE
-- #     FROM REST_REVIEW
-- #     GROUP BY MEMBER_ID
-- #     ORDER BY C DESC) AS R, MEMBER_PROFILE M


SELECT M.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, "%Y-%m-%d") AS REVIEW_DATE
FROM REST_REVIEW R, MEMBER_PROFILE M, (SELECT COUNT(*) AS C, MEMBER_ID
                                        FROM REST_REVIEW
                                        GROUP BY MEMBER_ID
                                        ORDER BY C DESC
                                        LIMIT 1) S
WHERE R.MEMBER_ID = S.MEMBER_ID 
    AND M.MEMBER_ID = S.MEMBER_ID
ORDER BY REVIEW_DATE ASC, REVIEW_TEXT ASC;