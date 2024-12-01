# CPP Cheat Sheet 

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

### 2차원 벡터 선언 시 
```cpp
vector<vector<int>> numbers(n+1, vector<int>(n+1, 0));
```

벡터 안에 벡터가 있어야 하므로 초기값을 지정해줄 벡터가 벡터 내부에 들어간다고 이해하면 된다. 


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
