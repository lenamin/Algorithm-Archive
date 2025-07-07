## [언어별 개발자 분류하기](https://school.programmers.co.kr/learn/courses/30/lessons/276036)

### `WITH ___ AS ()` 
```sql
WITH HAS_FLAGED AS (
    SELECT MAX(CASE WHEN SF.NAME = 'Python' THEN 1 ELSE 0 END) AS HAS_PYTHON,
           MAX(CASE WHEN SF.CATEGORY = 'Front End' THEN 1 ELSE 0 END) AS HAS_FE,
           MAX(CASE WHEN SF.NAME = 'C#' THEN 1 ELSE 0 END) AS HAS_CSHARP,
           DF.ID, 
           DF.EMAIL
    FROM DEVELOPERS DF, SKILLCODES SF
    WHERE DF.SKILL_CODE & SF.CODE = SF.CODE
    GROUP BY DF.ID, DF.EMAIL)
SELECT (CASE WHEN HAS_FLAGED.HAS_PYTHON = 1 AND HAS_FLAGED.HAS_FE = 1 THEN 'A'
             WHEN HAS_FLAGED.HAS_CSHARP = 1 THEN 'B'
             WHEN HAS_FLAGED.HAS_FE = 1 THEN 'C' END) AS GRADE, D.ID, D.EMAIL
FROM DEVELOPERS D
INNER JOIN HAS_FLAGED
ON D.ID = HAS_FLAGED.ID 
WHERE (CASE WHEN HAS_FLAGED.HAS_PYTHON = 1 AND HAS_FLAGED.HAS_FE = 1 THEN 'A'
            WHEN HAS_FLAGED.HAS_CSHARP = 1 THEN 'B'
            WHEN HAS_FLAGED.HAS_FE = 1 THEN 'C' END) IS NOT NULL
ORDER BY GRADE, D.ID
```

- 반드시 만든걸 `FROM` 에서 가져와야 쓸 수 있다  

<br>

### Trouble Shooting 
- **비트 연산으로 스킬을 어떻게 매핑해야 하는지 몰라서 막혔던 점**
    - DEVELOPERS 테이블의 `SKILL_CODE`는 여러 기술의 코드 합으로 저장되어 있음
    - SKILLCODES의 `CODE`는 2의 제곱수로 각각의 기술을 표현
    - 즉, 어떤 개발자가 특정 기술을 가졌는지는 `D.SKILL_CODE & S.CODE = S.CODE`로 판별해야 함
    
<br>

- **A등급 조건(Python + Front End)을 한 줄에서 판단하려다 실패**
    - 처음에는 `CASE WHEN CATEGORY='Front End' AND NAME='Python' THEN 'A'`로 접근함
    - 그런데 이 조건은 "하나의 기술이 동시에 Front End이고 Python인 경우"라서 성립 불가
    - 문제에서 A등급은 **두 개의 기술을 "각각" 보유해야 함**
    - 결국 한 줄로는 판단할 수 없고, **여러 줄의 기술 정보를 모아서 집계**해야했음 
        
<br>
        
- **개발자별 기술 보유 여부를 어떻게 표현해야 할지 몰라서 막힘**
    - Python 있는지, Front End 있는지, C# 있는지를 일일이 확인해야 하는데
        
        SQL에서는 각 조건을 **불리언 플래그처럼 표현**하는 게 필요했음
        
    - `MAX(CASE WHEN NAME = 'Python' THEN 1 ELSE 0 END)` 형태를 사용해서
        
        각 기술의 보유 여부를 `HAS_PYTHON`, `HAS_FE`, `HAS_CSHARP` 같은 컬럼으로 만듦
        
    - 이 작업이 되어야 나중에 `CASE WHEN ... THEN GRADE` 분기가 가능해짐


<br>

- **SELECT절에서 만든 GRADE 컬럼을 WHERE절에서 필터링하려다 에러 발생**
    - `SELECT CASE ... END AS GRADE`로 GRADE를 만들고,
        
        아래 WHERE절에서 `WHERE GRADE IS NOT NULL` 시도함
        
    - 하지만 GRADE는 SELECT절에서 **가상으로 만들어지는 컬럼이라**
        
        WHERE절에서는 아직 존재하지 않음
        
    - **해결 방법:**
        - `CASE ... END`을 WHERE절에서도 그대로 복붙


<br><br>


## [입양 시각 구하기(2)](https://school.programmers.co.kr/learn/courses/30/lessons/59413)

### `WITH RECURSIVE` 문법 
```sql
WITH RECURSIVE CTE명(컬럼명) AS (
    SELECT 초기값
    UNION ALL
    SELECT 재귀적으로 누적될 값 FROM CTE명 WHERE 종료 조건
)
SELECT ...
FROM CTE명;
```


- 초기값 : 재귀가 시작될 기준 값.
- UNION ALL : 다음 값을 누적해서 생성.
- 종료 조건 : 종료되지 않으면 무한루프 발생 주의!
- **CTE(Common Table Expression)** : 일시적으로 쓰이는 임시 결과 테이블.


    ```sql
    WITH RECURSIVE HOURS AS (
    SELECT 0 AS HOUR
    UNION ALL
    SELECT HOUR + 1 FROM HOURS WHERE HOUR < 23)
    ```


### 문제 요약
- 입양 시간(`DATETIME`)에서 시(hour)를 기준으로 **0시부터 23시까지 입양 건수를 집계**해야 함.
- 단, **해당 시간에 입양 기록이 없을 경우에도 0으로 출력되어야 함**.
- 기본적인 `GROUP BY HOUR(DATETIME)` 방식으로는 **데이터가 없는 시간대는 누락**됨.

<br>

### 시도한 방법과 실패 원인

1. `GROUP BY HOUR(DATETIME)`만 사용
    ```sql
    SELECT HOUR(DATETIME) AS HOUR, COUNT(*) 
    FROM ANIMAL_OUTS 
    GROUP BY HOUR(DATETIME)
    ```
    - 입양 기록이 있는 시간대만 결과에 포함됨.
    - **입양이 없는 시간대(예: 0~6시 등)**는 아예 출력되지 않음.
    
    <br>

2. LEFT JOIN으로 같은 테이블끼리 JOIN 시도
    ```sql
    SELECT HOUR(O1.DATETIME), ...
    FROM ANIMAL_OUTS O1
    LEFT JOIN ANIMAL_OUTS O2 ...
    ```

    -  LEFT JOIN을 했지만 기준 테이블 자체가 시간 목록이 아님.
    -  없는 시간을 생성하지 못하므로 여전히 누락 발생.
    
    <br>

3. WITH RECURSIVE 없이 UNION ALL로 시간 목록 수동 생성
    ```sql
    SELECT 0 AS HOUR UNION ALL SELECT 1 ...
    ```
    
    -  데이터 누락 없이 출력 가능.
    -  코드가 길고 반복적이며 유지보수가 어려움.



<br><br>




## [조건에 맞는 개발자 찾기](https://school.programmers.co.kr/learn/courses/30/lessons/276034)

```sql
SELECT D.ID, D.EMAIL, D.FIRST_NAME, D.LAST_NAME
FROM DEVELOPERS D
WHERE D.SKILL_CODE & (SELECT SUM(CODE)
                      FROM SKILLCODES
                      WHERE NAME IN ('Python', 'C#')) > 0
ORDER BY D.ID ASC;
```

- SKILL_CODES의 NAME에 파이썬이나 C#이 있다면, 그 코드들을 합산하고, 비트마스킹 & 연산자한게 0보다 크다는 것 == 겹치는 부분이 하나 이상 있다는 것 
- JOIN은 굳이 필요없었음 → SKILLCODES NAME을 출력해야 하면 조인하는게 맞지만, 이 문제에서는 그런 조건이 없었으므로 서브쿼리만으로도 충분했음 

<br><br>

## [식품분류 별 가장 비싼 식품의 정보 조회하기](https://school.programmers.co.kr/learn/courses/30/lessons/131116)

- GROUP BY로 최대값을 구한 후, 해당 값을 만족하는 행의 다른 컬럼을 추출하려면, 서브쿼리와 조인을 사용해 조건 매칭해야 한다.

- 처음 쿼리 
    ```sql
    SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE, PRODUCT_NAME
    FROM FOOD_PRODUCT
    WHERE CATEGORY = '과자' || CATEGORY = '국' || CATEGORY = '김치' || CATEGORY = '식용유'
    GROUP BY CATEGORY
    ORDER BY 2 DESC
    ```
    : 이 때 출력은 테케는 통과했지만, 정답으로 인정되지 않았다. 
    : GROUP BY에서 MAX는 구할 수 있지만 출력된 PRODUCT_NAME은 반드시 MAX 값을 가진 PRODUCT_NAME이 아닐 수 있다는 것. 그래서 반드시 다음과 같이 서브쿼리 + 조인 형식으로 가져와야 함 

    ```sql
    SELECT C.CATEGORY, C.MAX_PRICE, P.PRODUCT_NAME
    FROM FOOD_PRODUCT P
    JOIN (SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE
        FROM FOOD_PRODUCT
        WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
        GROUP BY CATEGORY
        ORDER BY 2 DESC) AS C 
    ON C.CATEGORY = P.CATEGORY AND C.MAX_PRICE = P.PRICE
    ORDER BY 2 DESC;
    ```

<br><br>

## [자동차 종류 별 특정 옵션이 포함된 자동차 수 구하기 ](https://school.programmers.co.kr/learn/courses/30/lessons/151137)
#### 부분 문자열에서 쓸 수 없는 것들 
- `=` : 전체 문자열이 정확히 일치할 때만 사용됨 → 부분 문자열 비교 불가
- `IN (...)` : 문자열이 완전히 일치할 경우만 포함 → LIKE와 함께 쓸 수 없음

    ```sql 
    -- 부분 문자열 비교에 적절하지 않음
    WHERE OPTIONS IN ('%통풍시트%', '%열선시트%')

    -- 전체 문자열 비교이므로 안 맞음
    WHERE OPTIONS = '%통풍시트%'
    ```

#### 정확한 방식 
- `OR` + `LIKE` 사용할 것 
    ```sql
    -- 예: '통풍시트', '열선시트', '가죽시트' 중 하나 이상 포함된 경우
    WHERE OPTIONS LIKE '%통풍시트%'
    OR OPTIONS LIKE '%열선시트%'
    OR OPTIONS LIKE '%가죽시트%'
   ```


<br><br>

## [대여 횟수가 많은 자동차들의 월별 대여 횟수 구하기](https://school.programmers.co.kr/learn/courses/30/lessons/151139)
#### SQL 쿼리 작성 중 헷갈렸던 부분 정리

**1. 서브쿼리 조건을 본쿼리에서도 걸어줘야 함.**
- 특정 기간(예: 2022-08-01 ~ 2022-10-31) 내에 대여횟수가 5회 이상인 차량의 월별 대여 기록 추출
	
- 내가 한 실수: 서브쿼리에서만 날짜 조건을 걸고, 본쿼리에서는 걸지 않음<br> => 필터링된 차량의 전체 대여 기록이 월별 집계되어 의도와 다른 결과 발생<br> => 본 쿼리에도 같은 날짜 조건을 걸어줘야 함 
<br><br>

**2. 하지만 중복 쿼리가 생겨서 보기가 싫다. 이를 어떻게 피할 수 있을까??? ! -> CTE, WITH절 사용**
	
- CTE(Common Table Expression, WITH절)를 사용해 날짜 조건을 한 번만 작성하고 재사용 (but MySQL 8.0 이상부터 사용가능) 

```sql
WITH FilteredHistory AS (
    SELECT *
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
),
QualifiedCars AS (
    SELECT CAR_ID
    FROM FilteredHistory
    GROUP BY CAR_ID
    HAVING COUNT(HISTORY_ID) >= 5
)
SELECT 
    MONTH(F.START_DATE) AS MONTH,
    F.CAR_ID,
    COUNT(F.HISTORY_ID) AS RECORDS
FROM 
    FilteredHistory F
JOIN 
    QualifiedCars Q ON F.CAR_ID = Q.CAR_ID
GROUP BY 
    MONTH(F.START_DATE), F.CAR_ID
ORDER BY 
    MONTH ASC, F.CAR_ID DESC;
```

<br><br>

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
  
