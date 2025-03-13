### CASE WHEN 대신 ELT + FIELD 
- `FIELD(값, 비교값1, 비교값2, ...)`
  - 값이 비교값 목록에서 몇 번째인지 반환함 -> 값 없으면 0 반환
 
- `ELT(N, str1, str2, ...)`
  - N번째 위치의 문자열 반환하는 함수
  - N은 1부터 시작한다 (* 주의할 것)
 
- 둘 합치면 : `ELT + FIELD`
  `ELT(FIELD(STATUS, 'SALE', 'RESERVED', 'DONE'), '판매중', '예약중', '거래완료') AS STATUS`
  형식으로 표현할 수 있다.
  내가 작성했던

  ```sql
   (CASE 
        WHEN STATUS = "RESERVED" THEN "예약중"
        WHEN STATUS = "DONE" THEN "거래완료"
        WHEN STATUS = "SALE" THEN "판매중" END) AS STATUS
  ```
  과 같은 역할! 
  
