# Topology


### Topology Sort 
- 사이클이 없는 방향 그래프에서 사용할 수 있는 정렬 알고리즘 (노드를 선형적으로 정렬한다)
- 로직
  1. **진입차수 계산**: 각 노드로 들어오는 간선의 수를 계산하여 indegree 배열에 저장한다
  2. **진입차수가 0인 노드 찾기**: indegree 배열에서 진입차수가 0인 노드를 모두 찾아 큐에 추가한다. (들어오는 간선이 없는 노드)
  3. **노드 처리**: 큐에서 노드를 꺼내 정렬 결과에 추가하고, 해당 노드와 연결된 모든 노드의 진입차수를 1 감소시킨다.
  4. **반복**: 큐가 빌 때까지 위 과정을 반복한다.
 
- 시간복잡도 O(v+e)