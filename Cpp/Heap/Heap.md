

## [multiset을 활용한 7662 이중 우선순위 큐 풀이](https://www.acmicpc.net/problem/7662)

### 1. `*ms.begin()` vs `ms.begin()` 차이

- `ms.begin()`은 iterator를 반환한다.
- `*ms.begin()`은 해당 iterator가 가리키는 값 <br>
    → 즉, 실제 값을 쓰려면 `*`를 붙여야 한다.

    ```cpp
    multiset<int> ms = {3, 5, 7};
    auto it = ms.begin();   // iterator
    int val = *ms.begin();  // 3
    ```

<br>

### 2. `ms.end()`는 마지막 값이 아니다

- `ms.end()`는 마지막 원소의 다음 위치를 가리킨다.
- 실제 마지막 원소를 접근하려면 `--ms.end()`를 사용해야 한다.

    ```cpp
    auto maxIt = --ms.end(); // 마지막 원소의 iterator
    int maxVal = *maxIt;
    ```

<br>

### 3. multiset은 중복 값을 허용

- set은 중복된 값을 허용하지 않지만, multiset은 가능하다.
- 삽입 시 자동 정렬되며, 중복된 값도 유지된다.

<br>

### 4. `erase(iterator)` vs `erase(value)` 차이

- `erase(iterator)` <br>
    : 해당 위치에 있는 그 반복자 하나만 삭제함 

- `erase(value)` <br>
    : 값과 일치하는 모든 원소 삭제함! 중복된 값이 있다면 모든 값이 삭제됨. <br>
    : 삭제된 값이 있는 경우 몇 개가 삭제되었는지 **원소의 개수**를 리턴 

    ```cpp
    multiset<int> ms = {5, 5, 7};

    ms.erase(ms.begin()); // 5 하나만 삭제 → {5, 7}
    ms.erase(5);          // 모든 5 삭제 → {7}
    ```
