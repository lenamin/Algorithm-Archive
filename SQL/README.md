

## [문제](https://school.programmers.co.kr/learn/courses/30/lessons/151141)
[코드](https://github.com/lenamin/Algorithm-Archive/commit/29798a0aad0b286bb492e36125088123820680ed)
### `DATEDIFF` vs `END_DATE - START_DATE` 의 차이 
| 함수 | 설명 | 특징 |
|------|------|------|
| `DATEDIFF(END_DATE, START_DATE)` | 두 날짜 간의 차이를 반환 | **날짜 차이(일수)를 자동 계산** |
| `END_DATE - START_DATE` | 직접 빼서 차이를 구함 | **DBMS에 따라 동작 방식이 다를 수 있음** |

- `DATEDIFF(H.END_DATE, H.START_DATE) + 1`로 **대여 첫날도 포함하도록 계산**  
- `END_DATE - START_DATE`도 사용할 수 있지만 DBMS에 따라 예상치못한 결과 나올 수 있으므로 웬만하면 DATEDIFF를 사용하도록 하자 


### LEFT JOIN vs INNER JOIN 
| **`INNER JOIN`** | `JOIN`하는 두 테이블 모두 해당하는 데이터가 있는 경우만 가져올 때 | `HISTORY_ID`와 `CAR_ID`가 매칭될 때만 대여 기록을 가져올 때 |
|-----------|-----------------|------|
| **`LEFT JOIN`** | 한쪽 테이블의 데이터가 없어도 유지해야 할 때 | 할인율이 없는 경우에도 대여 기록을 유지할 때 |

- 만약 할인율 없는 경우에도 대여 기록을 유지해야 했다면, INNER JOIN으로는 아예 사라져버렸다.
- LEFT JOIN 한 다음 `COALESCE`로 NULL인 경우를 취급해주는게 맞았음!! 

### MYSQL에서의 GROUP BY 
```sql
ON D.CAR_TYPE = '트럭' AND T.DURATION >= 
    (CASE WHEN D.DURATION_TYPE = '7일 이상' THEN 7
          WHEN D.DURATION_TYPE = '30일 이상' THEN 30
          WHEN D.DURATION_TYPE = '90일 이상' THEN 90 ELSE 0 END)
GROUP BY HISTORY_ID
```
- 이렇게 조회한 다음, `GROUP BY`만 하고도, `MAX` 처리를 하지 않고도 정상적인 값이 나왔음.
- 하지만 MySQL에서는 implicitly 하게 선택한다고 한다 : `MAX` 로 명시적으로 선택할 수 있도록 할 것 

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
  
