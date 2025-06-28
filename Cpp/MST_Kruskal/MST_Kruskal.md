# MST_Kruskal

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