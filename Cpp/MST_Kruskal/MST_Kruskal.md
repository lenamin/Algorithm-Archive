# MST_Kruskal


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