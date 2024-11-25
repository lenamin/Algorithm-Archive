#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// 일단 입력받은 값을 연결리스트에 넣자 
static vector<list<int>> graph;
vector<bool> visited;
static int vertex, edge;

void dfs(int v);
void bfs(int v);

int main()
{
  int start;
  cin >> vertex >> edge >> start;
  visited = vector<bool>(vertex + 1, false);
  graph.resize(vertex + 1);
  
  for (int i = 0; i < edge; i++) {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }

  for (int i = 1; i < vertex + 1; i++) {
    graph[i].sort();
  }
  
  dfs(start);
  cout << '\n';
  fill(visited.begin(), visited.end(), false);
  bfs(start);
}

void dfs(int v) {
  if (visited[v]) {
    return;
  }
  visited[v] = true;
  cout << v << " ";

  for (auto g : graph[v]) {
    if (!visited[g]) {
      dfs(g);
    }
  }
}

void bfs(int v) {
  queue<int> waitingQueue;

  waitingQueue.push(v);
  visited[v] = true;

  while (!waitingQueue.empty()) {
    int current = waitingQueue.front();
    waitingQueue.pop();
    
    cout << current << " ";
    
    // if (visited[current]) {
    //   continue;
    // }

    for (int a : graph[current]) {
      if (!visited[a]) {
        visited[a] = true;
        waitingQueue.push(a);
      }
    }
  }
}