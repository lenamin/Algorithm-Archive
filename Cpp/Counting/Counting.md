## [실패율](https://school.programmers.co.kr/learn/courses/30/lessons/42889)

> **Trouble Shooting**

### 1. `0으로 나누는 예외 처리` 누락

- 도달자가 0명일 때 `fail / total` 연산에서 런타임 오류 발생 가능
- `if (total == 0) rate = 0.0;`
- **분모가 0일 경우 반드시 조건 처리 필요!**
    

<br>

### 2. `double 나눗셈 연산` 캐스팅 오류

- `int / int` 연산으로 인해 실패율이 항상 0으로 나옴
    : `(double)fail / (double)total`
- 정수끼리 나누면 정수 나눗셈! -> 적어도 하나는 double로 명시적 형변환 필요
    

<br>

### 5. `정렬 기준 커스터마이징` 까먹음

- `pair` 정렬에서 실패율 기준 + 인덱스 기준 조건을 직접 정의해야 함
    ```cpp
    sort(fail.begin(), fail.end(), [](const pair<double, int> &a, const pair<double, int> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    });
    ```

<br><br>

> **Prefix Sum 적용해서 O(n x m) 을 O(n + m + nlogn)으로 줄이기**

### 2중 for 문 → 카운팅 최적화를 통해 더 줄일 것
- 먼저 실패자 수만 미리 센다
    
    ```cpp
    for (int s : stages) {
        if (s <= N) failCount[s]++;
    }
    ```

<br>

- 도달자 수를 구한다. (using실패자 수 누적값)
    
    ```cpp
    for (int i = 1; i <= N; i++) {
        successCount[i] = total; // successCount의 초기값은 
        
        total -= failCount[i];
    }
    
    ```

<br>

- 처음엔 모든 사람이 **1번 스테이지부터 시작**할 수 있으니까 `successCount[1] = 전체 인원`

<br>

- 그 다음엔 1번에서 실패한 사람들은 **2번에 못 도달**하니까 `successCount[2] = 전체 인원 - failCount[1]`

<br>

- 3번 스테이지는 `successCount[3] = 전체 인원 - failCount[1] - failCount[2]`
- 계속 이런 식으로 **누적해서 도달자 수를 줄여나가는 방식**


<br>

- **실패율 구하기**
    
    ```cpp
    for (int i = 1; i <= N; i++) {
        if (successCount[i] == 0) { fail.push_back({0, i}); }
        else {
            double d = (double)failCount[i] / (double)successCount[i];
            fail.push_back({d, i});
        }
    }
    
    ```