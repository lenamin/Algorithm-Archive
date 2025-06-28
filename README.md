# 시험 직전에 보는 Algorithm Archive


### [과일 탕후루 문제를 통해 익히는 Sliding Window](https://www.acmicpc.net/problem/30804)

#### 어려웠던 점 
- 일단 문제 이해에 어려움을 겪음 → 이는 슬라이딩 윈도우에 익숙하지 않아 생긴 문제로 슬라이딩 윈도우 로직 기본 구현에 집중함 <br>

#### **슬라이딩 윈도우 문제인지 확인하는 방법** 
  - 연속된 구간에 대한 문제인지? (부분배열) 
     : 연속된 수들의 합 or 연속된 구간의 길이 or 연속된 구간 내 최대/최소값 등  <br>
  - 구간을 좌우로 확장 및 축소해가면서 조건을 체크할 수 있는지? 
     : 조건을 초과하면 앞쪽을 잘라서 다시 조건을 만족시킬 수 있는지? <br>
  - 매번 전체를 계산하는게 아닌, 누적값을 구할 수 있나? 윈도우 이동 시 계산을 빠르게 할 수 있나? 
  - 조건을 만족하는 최대/최소 길이 or 합을 구하라는 문제인지? 
  - 완전탐색을 할 경우 n이 10만 이상이라 터질 때, 혹시 슬라이딩 윈도우를 사용해서 이를 해결할 수 있는가? 
<br>

#### 슬라이딩 윈도우 로직 
1. `left`, `right` 포인터를 사용해 현재 윈도우 정의한다. (배열 안에서 현재 탐색 중인 구간의 시작과 끝)
    ```cpp
    int right = 0, left = 0;
    ```
    <br>

2. `right` 하나씩 늘리며 새로운 과일을 윈도우에 추가한다. 
    ```cpp
    while (right < n) { 
      ...

      right++;
    }
    ```
    <br>

3. 새로운 과일이 들어왔을 때 `count[과일번호]`를 증가시키고, 처음 들어온 종류면 (`count[fruits[right]] == 0` 이면) `kcnt` 도 함께 증가시킨다. 
    ```cpp
    if (count[fruits[right]] == 0) {
      kcnt++; 
    }
    count[fruits[right]]++; 
    ```
    <br>

4. 과일 종류 수가 2를 초과하면, `left`를 이동해 윈도우에서 과일 제거하고, 그 과일 개수가 0이되면 (`count[fruits[left]] == 0` 이면) `kcnt` 를 1 감소해서 업데이트 한다. 
    ```cpp
    while (kcnt > 2) {
      count[fruits[left]]--; // 우선 왼쪽끝의 과일 종류수 카운트를 1 줄이고 
      
      if (count[fruits[left]] == 0) {
          kcnt--; // 만약에 삭제 후 더 이상 없을 때 kcnt 업데이트하고 
      }

      left++; // 그러고나서 옮겨야지. 그래야 옮기기 이전의 값이 줄여지니까 
    }
    ```
    <br>


5. 현재 윈도우 길이 `right - left + 1` 과 현재 `answer` 비교해서 최대값 갱신

<br>

#### 구현 중 실수
- count설정과 `left++` 순서 <br>
  : 과일 제거 전에 `left++`를 하게되면 윈도우에서 아직 제거되지 않은 과일이 빠진다. 항상 값 변경 후, 인덱스를 이동하도록 순서 유지할 것!! 

<br><br>


### [Floyd-warshall 알고리즘 활용한 경로찾기 문제 해결하기](https://www.acmicpc.net/problem/11403)
- **플로이드 워셜 알고리즘** 
  - 경로의 최단 거리 대신 도달 여부만 판단한다 (1 or 0)
  - 모든 정점 (i, j) 간의 최단거리 또는 도달 가능성 여부를 구해야 할 때 사용
  - **사용 가능한 조건**
    - 인접행렬 or 인접리스트 && n ≤ 500 일 때 (3중 for문이므로 노드 수가 500이하일 때만 사용가능!!) 
    - **모든 정점 쌍** 이라는 말 나오면 플로이드워셜 떠올릴 것! 

- 로직 
  - 인접 행렬 기반 입력받기 
  - 3중 for 문으로 모든 중간 노드 k에 대해 경로를 갱신한다. 
    - adj[i][j]에 i에서 j로 갈 수 있는 길이 있는 경우를 일단 입력받음.
    - k를 중간경로로 사용함. 만약 i - k - j 가 있는 경우 그니까, adj[i][k]가 1이고, adj[k][j] 가 1이면 결국 adj[i][j]는 1이니까 이 값을 갱신해 줄 있는 것. 
    - 그래서 다음과 같은 코드로 구현할 수 있다 

  ```cpp
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][k] && adj[k][j]) {
          adj[i][j] = 1;
        }   
      }
    }
  }
  ```
<br><br>


### [Parametric Search](https://www.acmicpc.net/problem/2805)
- **Parametric Seach**
  - 어떤 조건을 만족하는 최대/최소값을 이진 탐색을 통해 찾는 기법. 
  - 정답이 존재하는 수의 범위를 이진탐색하는 방식으로, 배열 탐색이 아닌, 값 그 자체에 대한 탐색을 진행한다! 
  - 그래서 처음에 익숙한 이진트리로 시도했다가, 인덱스 기반이 아니라 당황했었는데 이런 값 기반의 이진탐색을 Parametric Search 라고 한다. 

- 로직 
  - 이진 탐색 범위 정의할 것. 이 문제에서는 (절단기 높이의 최소와 최대가 start, end가 됨)
  - 조건 판단 함수 구현 : 현재 값 (mid : 절단지점값)이 t보다 크거나 같은지 체크해서, 
  - 만족하는 경우는 일단 임시로 저장해두고 더 큰 값이 있는지 start를 mid + 1로 수정해서 다시 탐색 
  
- 실수한 부분 
  - 정상적으로 테케는 잘 뜨는데 오답이 떠서 보니 sum을 long long으로 선언해주지 않아서 틀린 것. 
  - 누적합은 범위 꼭 확인해서 `long long` 타입으로 선언할 것!! 

<br><br>


### [IOIOI 문제 접근](https://www.acmicpc.net/problem/5525)
[풀이](https://github.com/lenamin/Algorithm-Archive/commit/492c52b4dab974143db1c19f119897ce4e5282b8)
- 첫 번쨰 풀이 (substr 활용) <br>
  : `substr` 이용해서 target 크기만큼 잘라서 비교했음. `substr`의 경우 복사를 하기 때문에 문제의 절반 조건을 통과하지만, 일부 테케에서는 시간초과가 떠서 50점밖에 나오지 않았음. 
  ```cpp
  for (int i = 0; i <= m - 2 * n; i++) {
    if (target == s.substr(i, 2 * n + 1)) {
        cnt++;
    }
  }
  ``` 

- 슬라이딩 윈도우 활용 
  - 슬라이딩 윈도우 : 일정한 범위를 유지하면서 포인터를 이동해 문제를 해결하는 방식 
  - 이 문제에서의 윈도우는 : 패턴 시작점에서 "OI" 쌍이 몇 번 반복되었는지 세고, 
  - 그 연속된 "OI" 개수가 n보다 같거나 커지면 일치하니까 상태변수 증가시킴 

- **예외처리**
  - 겹치는 패턴 또한 고려해야 했음 
  - 기존 그냥 슬라이딩 윈도우를 구현할 경우, 이미 관찰한 부분은 지나가버리기 때문에 패턴이 겹치는 경우는 탐색하지 못함 
  - while 문 종료 후에 마지막 'I'를 살려서 탐색 계속함 
    ```cpp
    if (cnt > 0) { 겹치는 'I' 때문에 i -= 1; } <- 되돌려놓는것!! >
    ```
    : 이 부분이 핵심이었다. 겹치는 부분을 어떻게 처리할지 몰라서 substr 썼던 거였는데, 되돌림으로써 재활용할 수 있는 것이었음! 
    : 대놓고 슬라이딩 윈도우 문제 아닌 것 같아도 슬라이딩 윈도우를 응용할 수 있는 문제였음 - * 
 <br><br>

### DP한 실수들 
- 점화식을 통해 나올 수 있는 값을 초기화를 통해 지정했더니 오답 발생
  : 점화식으로 유도되는 값은 무조건 반복문 안에서 dp 연산이 될 수 있도록 할 것!! 

- MOD 연산을 마지막 출력에서만 처리하니 오답이 발생함 
  : 자료형에 따라 오버플로우 발생가능하니까 MOD 연산하라고 한 의도 파악할 것 
  : 그러므로 매 점화식 값에서 MOD 연산을 해줘야 하는 것 !! 
<br><br>

### 큐로 원형 순회 구조 만들기 

```cpp
  queue<int> q;
  for (int i = 1; i <= n; i++) q.push(i);

  while (!q.empty()) {
      for (int i = 0; i < k - 1; i++) {
          q.push(q.front());
          q.pop();
      }
      ans.push_back(q.front());
      q.pop();
  }
```

- 기존 vector + index 로 관리할 때 idx 관리의 어려움을 queue로 해결할 수 있었다! 

### stable_sort 구현하기
#### `stable_sort` 
  C++ 표준 라이브러리 `<algorithm>`에 포함된 **정렬 함수**로, **동일한 키 값에 대해서는 원래의 입력 순서를 유지**한다.

```cpp
#include <algorithm>

stable_sort(시작_반복자, 끝_반복자, 비교_함수);
```

: `sort()`와 달리 **안정 정렬(stable sort)**을 제공 <br>
: 내부적으로는 일반적으로 **Merge Sort** 기반으로 구현되어 있다고 한다.



#### 시간 복잡도

| 조건              | 시간 복잡도             |
|------------------|--------------------------|
| 평균/최악의 경우  | O(N log² N) (일반적으로) |
| GNU/GCC STL 구현 | O(N log N)               |

> **참고:** `sort()`는 `IntroSort` 기반으로 평균적으로 더 빠르지만, 입력 순서를 보장하지 않는다. (second값도 정렬해버림)

```cpp
// 예시
vector<pair<int, string>> v = {{21, "Alice"}, {19, "Bob"}, {21, "Charlie"}};

stable_sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.first < b.first;
});
// 출력: 19 Bob, 21 Alice, 21 Charlie  → Alice가 Charlie보다 먼저 출력됨
```

<br><br>

### [BFS를 활용해 치즈 녹이는 문제](https://www.acmicpc.net/status?user_id=julieeee&problem_id=2636&from_mine=1) 정리 

#### 이 문제에서 BFS를 사용해야 하는 이유 
- 외부 공기 탐색 : (0, 0)에서 시작해 외부 공기만 다라가며 치즈를 찾아야 한다 
- 내부 공기를 무시해야 하기 때문 : DFS는 경로 추적이 어려워 내부 공기와 혼동하기 쉽다 
- 동시 녹이기 구현 : BFS 로 탐색해서 치즈를 한 번에 녹이면 시간 흐름 표현이 쉽다 (while 한바퀴가 한시간)

#### 로직 
1. 입력 처리 (배열, visited 준비)
2. while (치즈가 남아있을 때까지 반복):
    1. 현재 치즈 개수 세기 → lastCC에 저장
    2. visited 초기화
    3. cheese 목록 초기화
    4. BFS(0,0) → 외부공기 따라가며 치즈 후보 수집
    5. 수집된 치즈들을 arr에서 0으로 녹임
    6. 시간(hour) 증가
3. 결과 출력: 총 시간, 마지막 치즈 수

#### 실수들 
- vector<vector<T>> 에는 `fill()`을 상요할 수 없음 -> 일일이 그냥 이중 for 문 돌려야 함 

### [숫자처럼 정렬해야 하는 문자열 처리 문제](https://www.acmicpc.net/problem/2870) 정리
문자열 속에 섞여 있는 숫자들을 추출해서 이를 숫자 기준으로 정렬 (비내림차순) 하는 문제

#### 1. 사용자 정의 정렬 함수 `cmp()` 
- 숫자는 문자열로 표현되어 있어도 숫자처럼 정렬되도록 해야 함 
- 기준은 1) 길이가 짧으면 작은 숫자 2) 길이 같을 때는 사전 순 비교 

  ```cpp
  bool cmp(string &a, string &b) {
      // 길이 기준으로 정렬 (숫자가 작을수록 길이가 짧음)
      if (a.size() != b.size()) return a.size() < b.size();

      // 길이가 같으면 사전 순 비교 (문자열 "123" < "456" 그대로 성립)
      return a < b;
  }
  ```

#### 2. `stoi` 사용했을 때 runtime error (out_of_range) 발생한 이유 
- 문제조건을 놓쳤다 : 100~200자까지 들어올 수 있음. `long long` 타입을 사용해도 담을 수 없는 범위임 
- 그래서 `1` 에서 정리한 함수를 정의해 문자열을 숫자처럼 정렬할 수 있도록 함 


#### 3. 숫자의 앞자리 0 처리방법 
- 내가 구현한 방식 (비어있지 않고, 기존 ts가 0이면 현재 숫자로 덮어씀)
  ```cpp
  if (isdigit(c)) {
    if (!ts.empty() && ts == "0") {
        ts = c;
    } else {
        ts.push_back(c);
    }
  }
  ```

- `find_first_not_of("0")` 함수 사용도 가능함 
  ```cpp
     aa.erase(0, aa.find_first_not_of('0'));
     bb.erase(0, bb.find_first_not_of('0'));
  ```




### Fast Exponentiation 정리 
- 백준 1629 곱셈문제를 단순히 곱하면 시간초과 남. <br>
→ 분할정복을 이용해 시간복잡도를 O(logb)로 줄인다 how? 

#### 반복문 풀이 흐름
| 변수 | 의미 |
|------|------|
| `result` | 누적 결과값 (초기값 1) |
| `base` | A^{2^i} mod C, 계속 제곱됨 |
| `B` | 지수, 매 루프마다 2로 나눠짐 |

#### 반복 과정 (비트 연산 이용)
```cpp
while (B > 0) {
    if (B & 1)             // 현재 비트가 1이면
        result = result * base % C;
    base = base * base % C; // 다음 제곱 준비
    B /= 2;                 // 다음 비트로 이동
}
```
 +`long long` 으로 선언하는 것도 잊지말기! 

<br>


### DP에서 점화식 초기화할 때 경계값 초기화하기! 
- 경계값(맨 윗줄, 맨 왼쪽줄)은 별도로 초기화해야 함

- 첫 행 (i = 0) : 위쪽에서 올 수 없으므로 **왼쪽 값만 누적**
  ```cpp
    for (int j = 1; j < m; j++) {
      dp[0][j] = dp[0][j - 1] + miro[0][j];
  }
  ```

- 첫 열 (j = 0) : 왼쪽에서 올 수 없으므로 **위쪽 값만 누적**
  ```cpp
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + miro[i][0];
  }
  ```

- 내가 했던 실수 
  ```cpp
  dp[0][1] = miro[0][1]; // 누적 없이 값만 넣으면 안 됨
  dp[1][0] = miro[1][0]; 
  ```

### DFS를 통해 싸이클 여부 판별할 때 
- 이미 방문한 정점에 다시 도달하는지 확인해야하는게 맞지만, 단순하게 그냥 방문한 적 있고 && 같은 정점 인 조건만으로 검색하면 안됨 !! (백트랙킹 했을 때 그냥 지나가는건데 싸이클로 판별할 수도 있다)
- 그래서 어떻게? <br>
바로 이전 위치에서 다시 오는 것은 싸이클이 아닌 것 <br>
→ px, py (이전 좌표) 사용해서 이전좌표에서 오는 건지, 다른 좌표에서 오는 건지 구분해서 판단한다

  ```cpp
  if (dot == board[nx][ny]) {
      if (visited[nx][ny] && !(nx == px && ny == py)) {
          isCycle = true; // 싸이클 발견
          return;
      }
      if (!visited[nx][ny]) {
          dfs(nx, ny, x, y); // 다음 위치로 이동
      }
  }
  ```

### 방향 회전 및 후진 처리 
- 방향은 0 : 북, 1: 동, 2: 남, 3: 서로 표현함 
- 배열 인덱스 순서로 방향 이동 관리! (dx, dy) 

#### 1. 왼쪽 회전 (반시계 방향으로 한 칸 이동할 때)
- 현재 방향이 d 라고 한다면 왼쪽방향은 `(d + 3) % 4` 
- -1 쓰는 대신 + 3 % 4 를 사용해서 음수 인덱스를 방지함! 


#### 2. 후진 
- 현재 방향이 d 라고 한다면, 후진은 (d + 2) % 4 -> 반대방향으로 두 칸 이동하니까 후진이 되는 것 ! 


### Merge Sort구현에서 실수한 것들
1. 배열 크기만큼 tmp를 한 번 할당하고, 병합할 구간만 복사하자 <br>
  - tmp를 매번 새로 할당하면 불필요한 시간복잡도(O(n)) 증가
  - tmp를 전체 복사하면 비효율적이며, 시간 초과 발생 가능
  - tmp를 한 번만 할당하고, 병합할 범위만 복사
    ```cpp
    for (int i = s; i <= e; i++) { 
        tmp[i] = arr[i];  // 병합할 부분만 복사해야 시간 초과 방지
    }
    ```
    <br>
2. swap 횟수는 idx2 - k로 업데이트해야 한다.
  - idx1이 이동할 때 swap을 증가시키면 잘못된 값이 나올 수 있음 (idx1이 이동하는 것은 기존 순서를 유지하는 것이므로 swap이 발생하지 않으니까) 
  
    ```cpp
    while (idx1 <= m && idx2 <= e) {
        if (tmp[idx1] > tmp[idx2]) {  
            arr[k] = tmp[idx2];  
            result += (idx2 - k);  // 오른쪽 값이 앞으로 오면서 swap 발생  
            k++;
            idx2++;
        } else {
            arr[k] = tmp[idx1];  // 왼쪽 값은 순서 그대로 삽입  
            k++;
            idx1++;
        }
    }
    ```
    
    <br>
3. 병합 정렬을 적용할 때 종료 조건을 확실히 처리!! 
  - if (s >= e) return;을 빠뜨리면 무한 재귀 발생
    ```cpp
    void merge_sort(int s, int e) {
        if (s >= e) return;  // 기저 조건 (배열 크기가 1이면 종료)
    }
    ```


### MST - Kruskal ([최소신장트리](https://www.acmicpc.net/problem/1197))
- 에지 기준 알고리즘으로 에지 리스트를 정의해야 함
  ```cpp
  typedef struct Edge {
    int f, t, w; // from, to, weight (하나의 에지가 from 노드로부터 to 노드까지 가중치 w 를 가진다) 
    bool operator > (const Edge& tmp) const { // 이러고 priority_queue를 greater<Edge>로 해주면 된다 
      return w > tmp.w;
    }
  }
  ```
- Union Find 할 때 자꾸 실수하는 부분
  - `find()` 함수에서 `return parent[a] = find(parent[a]);` 이다. <br>
    `parent[a]`를 하나로 생각하면 쉽다. 저 변수의 부모 노드를 찾아서 `parent[a]` 에 넣어주는 거니까!

- MST 는 결국 사이클이 없어야 하므로
  - Union Find 체크
  - 대표 노드 같지 않으면 사이클이 없는거니까 union 연산 수행
  - 수행할 때 마다 edge 수 증가하고, 이게 v-1 보다 커지면 while 문 종료 

### Dijkstra 
- 로직
  1. 인접리스트로 그래프 정보를 자료구조에 담는다
  2. 최단거리 배열 초기화하기 (충분히 큰 값으로)
  3. 값이 가장 작은 노드 골라서 우선순위 큐에 넣기
  4. 최단거리배열 현재 값과 선택 노드 최단거리배열 값 + 에지 weight 중 작은 값을 최단거리배열에 업데이트한다
  5. 3~4번 과정 반복 -> 출발 노드와 그 외 노드 간의 최단거리 구할 수 있음

- 인접리스트와 priority_queue 자료형에서 기억해야 할 것
  - 인접리스트에서는 `vector<vector<pair<int, int>>>` 에서 {노드, 가중치} 순으로 정의했다.
  - 하지만 우선순위 큐에서는 {가중치, 노드} 로 정의한다.
  - priority_queue를 min heap으로 만들었을 때 가중치를 오름차순 정렬을 하기 위한 것!

- 시간복잡도 : O(E logV)

- **다익스트라 구현 시 실수했던 부분들**
  - priority_queue 만들 때 최소힙으로 만들 것 (기본은 최대힙이다)
  - visited 배열은 최소비용이 확정된 정점들만 true 처리를 해주기 위한 용도이다 -> 그러니까 pq에서 꺼냈을 때만 확정할 수 있는 것 (최소힙에서 가장 작은 weight를 꺼낸거니까)
  - `distances[nextV]` 업데이트하고 가장 중요한 작업 : pq에 다시 push 해줘서 반영해줘야 weight가 진짜로 업데이트 된다!! 

### Topology Sort 
- 사이클이 없는 방향 그래프에서 사용할 수 있는 정렬 알고리즘 (노드를 선형적으로 정렬한다)
- 로직
  1. **진입차수 계산**: 각 노드로 들어오는 간선의 수를 계산하여 indegree 배열에 저장한다
  2. **진입차수가 0인 노드 찾기**: indegree 배열에서 진입차수가 0인 노드를 모두 찾아 큐에 추가한다. (들어오는 간선이 없는 노드)
  3. **노드 처리**: 큐에서 노드를 꺼내 정렬 결과에 추가하고, 해당 노드와 연결된 모든 노드의 진입차수를 1 감소시킨다.
  4. **반복**: 큐가 빌 때까지 위 과정을 반복한다.
 
- 시간복잡도 O(v+e)


### Union Find 알고리즘 
1. 1차원 배열을 이용해 유니온 파인드를 표현한다.
   - 처음에는 노드가 연결되어 있지 않으므로 각 노드가 대표 노드가 된다. 
   - 각 노드가 모두 대표노드이니까 배열은 자신의 인덱스 값으로 초기화한다. 

2. 2개의 노드 선택해 각각의 대표 노드 찾아 연결하는 Union 연산을 수행한다. 
3. 같은 집합에 있는 것을 연결한다
   - 만약 대표노드가 아니라면 대표노드까지 타고 올라가 찾아 연결한다. 
   - 여기서 대표노드를 찾을 때 find 연산을 활용한다 (또한 그래프를 정돈하고 시간복잡도를 줄인다)

4. find 연산
   1) 대상 노드 배열에 index 값과 value 값이 동일한지 확인한다 
   2) 동일하지 않으면 value 값이 가리키는 index 위치로 이동한다 
   3) 이동위치의 index 값과 value 값이 같을 때 까지 1~2 반복한다. -> 재귀함수로 구현 
   4) 대표노드에 도달하면 재귀 빠져나오고 거치는 모든 노드값을 대표 노드 값으로 변경한다. 


### Type Casting
- 문자에서 숫자로 형변환
  ```cpp
  #include <string>
  
  string sNum = "1234";
  string sNum_d = "1234.56";
  
  int inum = stoi(sNum);
  long lnum = stol(sNum);
  double dnum = stod(sNum_d);
  float fnum = stof(sNum_d);
  ```
- 숫자에서 문자로 형변환
  ```cpp
  #include <string>

  int inum = 1234;
  long lnum = 1234;
  double dnum = 1234.56;
  float fnum = 1234.56f;

  string intToString = to_string(inum);
  string longToString = to_string(lnum);
  string doubleToString = to_string(dnum);
  string floatToString = to_string(fnum);
  ```

### 부분 합 구하기 
- 특정 구간의 일부 합을 구할 때 매번 합을 구하게 되면 효율이 떨어져 시간 초과가 날 수 있다.
- 각 자리수의 합을 구한 배열을 미리 구해놓고 (배열 값 받을 때)
  > S[i] = S[i-1] + A[i]

### 입력 출력 시간초과 막기 위한 코드 
```cpp
ios::sync_with_stdio(false); // c++ 표준 스트림과 C 표준입출력의 동기화를 끊는다 
cin.tie(NULL);
cout.tie(NULL);
// cin과 cout의 묶음을 끊어서 cin 호출 시 cout의 자동 flush를 비활성화 한다! -> 그래서 성능이 향상되는 것 
```

- 위 코드의 영향
  - 입출력 작업이 많을 때, flush 줄여 성능 향상이 가능
  - cin이 모두 끝난 뒤 한번에 출력이 가능함
    
### 2차원 배열에서의 부분합 구하기 
- 2차원일 경우도 1차원 배열과 마찬가지이다.
  1) 우선 2차원 벡터에 원본 배열을 저장한다
  2) 저장하면서 동시에 해당 위치까지의 부분합을 저장한다
  3) 그리고 query 만큼 반복하며 요구사항을 계산한다.

- 부분합 구하기 (S[i][j]를 구할 때)
  > S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j] // 중복된 부분 제거, 두 번 삭제된 부분 다시 더해줘야 하므로 

### 나머지 합 구하는 경우의 수 구하기 
- (A+B) % C = ((A%C) + (B%C)) % C : 특정 구간 수들의 나머지 연산을 더해 나머지 연산을 한 값은 이 구간 합의 나머지 연산을 한 값과 동일함.
- 10986 풀이 순서
  1) n, m 입력받는다 + numbers, sums 배열 선언한다 
  2) numbers 배열 입력받는다 + 입력받으면서 각 부분합 배열을 구한다 
  3) 부분합 배열의 값을 m으로 모듈러 연산을 한 값을 받는다 -> 이걸 sums 배열에 업데이트 한다 
  4) 변경된 sums 배열에서 원소값이 0인 개수를 count 한다 
  5) sums 배열에서 원소값이 같은 인덱스 개수를 센다 -> 같은거 찾으면 되겠지
 
### [연결리스트 std::list로 구현하기]([b568a822232c9100633fe29d105cbd802322f05d](https://github.com/lenamin/BaekJoon/commit/a9039c13233b5d145eb8cd197f60da34f383d37c))
vertex가 5개, edgerk 6개인 연결리스트를 list를 이용해 값을 삽입해보자. 

- list 타입을 품고 있는 배열이니까 선언은 다음과 같이 할 수 있음
  
  ```cpp
  static vector<list<int>> graph;
  ```

- **static 키워드**
  - main 밖에서 static 없이 선언하게 되면 이 파일이 아니라 다른 파일에서도 접근할 수 있기 때문에 이름충돌의 가능성이 높아지고 유지보수하기가 어려워짐. 그래서 static으로 선언한 것
  - 그럼 크기가 변할때는? -> `graph.resize(vertex+1)` 처럼 resizes 를 해주면 된다.

- **데이터 삽입 및 연결리스트 형태로 데이터 연결**
  - 처음엔 vertex 를 기준으로 삽입하면 된다고 생각했으나, 인덱스 에러가 발생했다.
  - 이는 그래프는 edge에 의해 관계가 정의되기 때문에 edge를 기준으로 데이터를 삽입해야 했다.

- **무방향 그래프인 경우의 데이터 처리**
  
  무방향인 경우 u -> v, v-> u 모두가 가능하므로 하나의 관계에서 양쪽 모두를 해줘야 한다.
    ```cpp
    for (int i = 0; i < edge; i++) {
      int s, e;
      cin >> s >> e;
      graph[s].push_back(e);
      graph[e].push_back(s);
    }
    ```

### 전역변수로 depth를 관리할 떄의 위험성 
**static 남발하지 말기**
- dfs를 수행할 때 마다 depth를 1씩 증가하는 것을 트래킹하기 위해 depth 변수를 전역으로 선언하고 사용했더니, 각 dfs 에서 독립적인 depth 값을 가지지 못해 정확한 값을 가지지 못했다.
- dfs 함수의 매개변수로 depth를 보내어 관리하도록 하는 것이 안전하다.

**백트래킹**
- 백트래킹에서 가장 중요한 것은 만족하지 않을 때, 다시 이전으로 돌아가기 위해 방문했던 `visited` 를 초기화 해줘야 한다는 것이다!!!
  : 처음에 이걸 이해 못했다가 한참 헤맸다,,

### BFS, DFS 처럼 순회 순서가 중요한 경우 
- list 자료구조를 사용하게 되면 순서를 보장하지 않는다.
- 그래서 DFS, BFS를 호출하기 전에 정렬을 해주는게 필요하다.
  ```cpp
    for (int i = 1; i < vertex + 1; i++) {
    graph[i].sort();
  }
  ```

### 방향벡터 
- 네 방향
  ```cpp
  const int dy[] = {-1, 0, 1, 0};
  const int dx[] = {0, 1, 0, -1};
  ```
- 대각선 방향 포함한 여덟방향
  ```cpp
  int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
  ```

### 미로찾기 문제에서 실수한 부분들 
1. 경계값 조건 줄 때 bfs 함수의 매개변수로 받는 것과 cin으로 입력받은 배열 크기를 동일한 변수를 써버려서 경계값 검사가 정확하지 않았음 / 변수 이름에 주의하기
2. 문제 조건을 잘 보자. 붙여서 입력한다고 했으니 하나의 문자로 받아서 각 문자를 다시 배열에 넣어야했다.
   ```cpp
    for (int i = 0; i < n; i++) {
      string temp;
      cin >> temp;
      for (int j = 0; j < m; j++) {
        numbers[i][j] = temp[j] - '0';
      }
    }    
   ```

### Counting Star는 map또는 배열로 푼다 
- 문자열인 경우 → map으로,
- int나 '문자'인 경우 → 배열로 푸는게 좋다.

### 전역변수 vs 지역변수 
코테에서는 전역변수에 선언해주는 것이 좋다 → 0으로 알아서 초기화가 되기 떄문 (지역변수로 선언해주게 되면 쓰레기값이 들어가게됨) 

### 공백 포함한 입력받기 
cin 으로 받으면 공백을 기준으로 입력을 받게 됨 → 이는 `getline(cin, n)` 으로 받아줘야 한다. 

### split 함수 만들어서 쓰기 
```cpp
stringstream ss(문자열);
string temp;
while (getline(ss, temp, '구분자')) {
    // temp에 나눠진 문자열이 들어옴
}
```

```cpp
string s = "1,2,3";
stringstream ss(s);
string temp;
int sum = 0;
while (getline(ss, temp, ',')) {
    sum += stoi(temp);
}
cout << sum;
```

### vector에서 특정 값 제거하기 
```cpp
vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
```

### set에서 값 존재 확인 및 제거 
```cpp
if (myset.count(value)) {
  myset.erase(value);
}
```

### find, rfind 함수 
find는 원하는 값을 찾은 첫번째 위치를 반환한다. 
뒤에서부터 찾고싶다면, `rfind`를 사용하면 된다. 

```cpp
  for (auto f : fn) {

    if (splits[0].size() + splits[1].size() > f.size()) { 
      cout << "NE" << '\n';
    } else if (f.find(splits[0]) == 0 && f.rfind(splits[1]) == (f.size() - splits[1].size())) {
      cout << "DA" << '\n';
    } else {
      cout << "NE" << '\n';
    }
  }
```

- 반환 타입 착각하지 말것 -> `iterator` 타입으로 반환하니까 받을 때 `auto` 타입으로 받아서, 바로 erase 할 수 있음 
```cpp
auto it = find(vec.begin(), vec.end(), value);
if (it != vec.end()) {
    vec.erase(it);
}
```

### 벡터 순회 중에 값 지우는 문제 
그럼 요소가 앞으로 당겨져서 인덱스 꼬일 수 있다. 
vector 순회중에는 erase() 사용을 지양할 것. 필요한 경우 for문 종료 후 일괄처리 or set 사용을 고려할 것! (at 체육복 문제)

### set_difference 사용 시 결과 바로 넣을 수 있다 
```cpp
set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
```
단, `inserter` 로 감싸서 넣어줘야 한다는 것 잊지말기

### key <-> value 양방향 검색이 필요한 경우 자료구조를 하나만 쓰면 시간초과가 뜬다 
- 예를 들어, 아래와 같이 map<int, string> 타입으로 선언했을 경우, value 값을 통해 key를 찾으려할 때 O(n) 만큼의 시간복잡도가 걸리므로 시간초과가 뜨는 것.
  ```cpp
    for (int i = 0; i < k; i++) {
    string a;
    cin >> a;

    if (isdigit(a[0])) {
      int m = atoi(a.c_str());
      string key = p[m];
      cout << key << '\n';
    } 
    if (typeid(a) == typeid(string)) {
      for (const auto& pk : p) {
        if (pk.second == a) {
          cout << pk.first << '\n';
        }
      }
    } 
  }
  ```
- 자료구조 두 개를 만들어서 사용하면 map에서 find를 하는 건 O(logn)이므로 시간을 훨씬 단축할 수 있다.
  ```cpp
  map<string, int> mp;
  map<int, string> mp2;

  // ... 

  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;

    // 문자열이면 
    if (atoi(s.c_str()) == 0) {
      auto q = mp[s];
      cout << q << '\n';
    } else {
      int q = stoi(s);
      cout << mp2[q] << '\n';
    }
  }
  ```
### 입력받은 값이 int인지 string인지 검사하고 싶을 때 typeid 등을 쓰지 않아도 된다 
#### `atoi(s.c_str())` 활용하기 
- `c_str()` 은 string을 const char*로 바꿔주고
- 이를 `atoi` 에서는 정수로 변환해준다. 만약 문자열을 받지 않았다면 0을 반환하므로, 분기처리를 해서 문자열인지 문자열이 아닌지 확인할 수 있다!


### Connected Components 문제에서 카운트 시점과 사소한 실수들
#### 더 이상 연결요소가 없어서 for문으로 돌아왔을 때, dfs를 호출하기 전에 카운트를 증가시킨다. 

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (a[i][j] <= k) { 
            f[i][j] = 1; // 1이면 잠긴다 // 0이면 안잠기는 것

            if (visited[i][j] == 0) {
                cnt++;
                dfs(i, j);
            }
        }
    }
}
```

#### 만약 각 연결요소의 수를 카운트 하고 싶다면 (ex. 2667 단지번호 붙이기 문제) 
visited[y][x]를 방문처리 할 때 마다 증가시키면 된다. 

```cpp
void dfs(int y, int x) {
    cnt += 1;
    visited[y][x] = 1; // 현재 노드 방문처리 

    // 이제 (ny, nx) 계산해서 하나씩 주변에 있는지 체크해서 방문할 것 
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (visited[ny][nx] == 1) continue;
        if (arr[ny][nx] == 0) continue;
        
        dfs(ny, nx);
    }
}
```


#### 제발 전역으로 vector를 선언했고, 크기는 입력받은 뒤에 정해진다면 resize를 해주자..아니면 그냥 배열로 선언할 것


### 이차원 벡터 사용자 정의 정렬하기 
별도로 함수 만드는 것보다 람다함수 이용하니 훨씬 간결하다. 
```cpp
sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
   return a[1] < b[1]; 
});
```

### sort(), nth_element() 시간복잡도 
- sort() 시간복잡도는 평균 O(nlogn), 최악의 경우는 O(n^2)
- nth_element(1st, nth, last) 시간복잡도는 평균 O(n), 최악의 경우는 O(n^2)

- O(nlogn) 시간복잡도 안에 수행될 것임이 분명한데도 시간초과가 뜬다면? -> 결국 입출력 처리 때문인 것,,, 

### 우선순위 큐 
- 우선순위 큐를 정의해서 값들을 넣으면 알아서 최소힙 또는 최대힙으로 정렬된다.
- 우선순위 큐 순회하기
  ```cpp
    while (!pq.empty()) {
        int k = pq.top();
        pq.pop();
    }
    
  ```

### memset vs fill 
배열로 선언했을 때는 visited 같은 배열을 초기화해줄 때 `memset` 을 사용한다. 
```cpp
memset(visited, 0, sizeof(visited));
```

벡터로 선언했을 때는 `fill`을 사용한다. 
```cpp
fill(visited.begin(), visited.end(), false); 
```

### *max_element 
for문 돌려서 최대값 찾는것보다 훨씬 간편하다. 
```cpp
int M = *max_element(ans.begin(), ans.end());
```

- `*` 가 필요한 이유
  - `max_element` 는 반환하는 이터레이터 (주소)를 역참조해 값을 얻기 위해 필요하다.
  - `max_element`는 범위 내의 최대값의 위치를 반환하기 때문
  - 그래서 이 값을 사용하기 위해는 역참조로 해당 위치에 있는 실제 값을 가져와야 함
- 만약 `*`를 붙이지 않는다면?
  - 컴파일 에러 발생
  - `auto`로 선언하면 에러는 발생하지 않지만, 이터레이터의 메모리 주소를 반환한다. 
