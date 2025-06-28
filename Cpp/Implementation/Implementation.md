# Implementation

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

<br><br>


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
<br><br>

### 부분 합 구하기 
- 특정 구간의 일부 합을 구할 때 매번 합을 구하게 되면 효율이 떨어져 시간 초과가 날 수 있다.
- 각 자리수의 합을 구한 배열을 미리 구해놓고 (배열 값 받을 때)
  > S[i] = S[i-1] + A[i]

<br><br>

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
    
<br><br>

### 2차원 배열에서의 부분합 구하기 
- 2차원일 경우도 1차원 배열과 마찬가지이다.
  1) 우선 2차원 벡터에 원본 배열을 저장한다
  2) 저장하면서 동시에 해당 위치까지의 부분합을 저장한다
  3) 그리고 query 만큼 반복하며 요구사항을 계산한다.

- 부분합 구하기 (S[i][j]를 구할 때)
  > S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j] // 중복된 부분 제거, 두 번 삭제된 부분 다시 더해줘야 하므로 

<br><br>

### 나머지 합 구하는 경우의 수 구하기 
- (A+B) % C = ((A%C) + (B%C)) % C : 특정 구간 수들의 나머지 연산을 더해 나머지 연산을 한 값은 이 구간 합의 나머지 연산을 한 값과 동일함.
- 10986 풀이 순서
  1) n, m 입력받는다 + numbers, sums 배열 선언한다 
  2) numbers 배열 입력받는다 + 입력받으면서 각 부분합 배열을 구한다 
  3) 부분합 배열의 값을 m으로 모듈러 연산을 한 값을 받는다 -> 이걸 sums 배열에 업데이트 한다 
  4) 변경된 sums 배열에서 원소값이 0인 개수를 count 한다 
  5) sums 배열에서 원소값이 같은 인덱스 개수를 센다 -> 같은거 찾으면 되겠지
 
<br><br>

### [연결리스트 std::list로 구현하기]([b568a822232c9100633fe29d105cbd802322f05d](https://github.com/lenamin/BaekJoon/commit/a9039c13233b5d145eb8cd197f60da34f383d37c))
vertex가 5개, edge가 6개인 연결리스트를 list를 이용해 값을 삽입해보자. 

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
