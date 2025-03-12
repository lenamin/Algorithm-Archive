-- 조회수 가장 높은 중고거래 게시물에 대한 첨부파일 경로 조사
-- order by FILE ID DESC
-- 기본파일경로 : /home/grep/src/ 
-- 디렉토리 구분 : 게시글 ID 
-- 파일 이름 : 파일 ID, 파일이름, 파일확장자 
-- 조회수 가장 높은 게시물 중복 없음 

-- # SELECT * FROM USED_GOODS_BOARD -- BOARD_ID	WRITER_ID	TITLE	CONTENTS	PRICE
-- # SELECT * FROM USED_GOODS_FILE -- FILE_ID	FILE_EXT	FILE_NAME	BOARD_ID


SELECT CONCAT("/home/grep/src/", MAX_BOARD_ID.ID, "/", F.FILE_ID, F.FILE_NAME, F.FILE_EXT) AS FILE_PATH
FROM USED_GOODS_FILE F, (SELECT B.BOARD_ID AS ID
                        FROM USED_GOODS_BOARD B, USED_GOODS_FILE F
                        WHERE B.BOARD_ID = F.BOARD_ID
                        ORDER BY B.VIEWS DESC
                        LIMIT 1) AS MAX_BOARD_ID
WHERE MAX_BOARD_ID.ID = F.BOARD_ID
ORDER BY F.FILE_ID DESC;

-- 실수했던 부분 
    -- 1) 처음 작성했던 코드는 select 에서 MAX(B.VIEWS), B.BOARD_ID 로 조회했다. 
    --    이렇게 하면 크로스 조인이 된다고 한다. 왜냐하면 MAX 연산 값은 단일값인데 
    --    B.BOARD_ID는 여러 개가 나오기 때문에 sql이 혼란스러워하는 것 
    --    => 해결방법 : 
    --    서브쿼리를 이용하거나, 지금 수정한 것처럼 LIMIT 1을 쓰는것이 좋겠다 (그래서 문제에서 조회수 가장 높은게 하나라는 단서를 준 것 같다)
              
