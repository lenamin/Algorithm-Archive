#include <iostream>
#include <vector>
#include <list>

using namespace std;

static vector<list<int>> graph;
static vector<bool> is_visited;
void dfs(int v);

int main()
{
  int vertex, edge;
  cin >> vertex >> edge; // vertex 개수, edge 개수 

  graph.resize(vertex + 1);
  // is_visited.resize(v+1);
  is_visited = vector<bool>(vertex + 1, false);
  int count = 0;

  for (int i = 0; i < edge; i++) { // 여기서 edge개 만큼 돌리는 이유는,,,,? => 관계는 간선이 정의하니까 
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }
  
  for (int i = 1; i < vertex + 1; i++) {
    if (!is_visited[i]) {
      count++;
      dfs(i);
    }
  }
  cout << count << '\n';
}

void dfs(int v) 
{
  if (is_visited[v]) { return; } // 이미 방문했으면 볼 필요없으니까 탈출,, 

  is_visited[v] = true; // 현재 노드 방문했다고 기록
  
  for (auto v : graph[v]) {
    if (!is_visited[v]) {
      dfs(v);
    }
  }
}
