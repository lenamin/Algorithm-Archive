# 다시 풀어볼 문제들 
|문제번호|문제이름|분류|키워드|
|---|---|---|---|
|11655|[ROT](https://www.acmicpc.net/problem/11655)|구현|ascii활용 문자열|
|9996|[한국이 그리울 때 서버에 접속하지](https://www.acmicpc.net/problem/9996)|구현, 문자열|rfind, split, substr|
|2559|[수열](https://www.acmicpc.net/problem/2559)|부분합||
|1620|[나는야 포켓몬 마스터 이다솜](https://www.acmicpc.net/problem/1620)|맵|atoi(s.c_str()), map|
|프로그래머스|[네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)|BFS||
|2606|[바이러스](https://www.acmicpc.net/problem/2606)|DFS|인접리스트 활용|
|프로그래머스|[단속카메라](https://school.programmers.co.kr/learn/courses/30/lessons/42884)|그리디||
|프로그래머스|[야근지수](https://school.programmers.co.kr/learn/courses/30/lessons/12927)|Priority Queue||
|1325|[효율적으로 해킹하기](https://www.acmicpc.net/problem/1325)|BFS|*max_element, fill|
|322|[Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/?envType=study-plan-v2&envId=top-interview-150)|BFS||


# Cheat Sheet 

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
vector<string> split(const string& input, string delimeter) {
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimeter);

  while (end != string::npos) {
    result.push_back(input.substr(start, end - start));
    start = end + delimeter.size();
    end = input.find(delimeter, start);
  }
  result.push_back(input.substr(start));
  return result;
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
