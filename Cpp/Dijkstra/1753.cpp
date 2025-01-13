#include <bits/stdc++.h>
using namespace std;
int v, e, s;
typedef pair<int, int> edge;
vector<vector<edge>> alist;
vector<int> distances;
priority_queue<edge, vector<edge>, greater<edge>> pq; // 오름차순으로 정렬 -> min heap이 되도록 함 // 자료형, 컨테이너, 비교연산자
vector<bool> visited;

int main() {
    
    cin >> v >> e;
    cin >> s;

    alist.resize(v+1);
    distances.resize(v+1);
    visited.resize(v+1, false);

    // 최단거리배열 초기화 (0, 무한대, 무한대, ...)
    // distances[0] = 0;
    fill(distances.begin(), distances.end(), INT_MAX); 


    for (int i = 0; i < e; i++) {
        int vertex, to, w;
        cin >> vertex >> to >> w;
        alist[vertex].push_back({to, w});
    }

    // 다익스트라 알고리즘 수행 
    // 출발 노드 pq에 넣고 시작  pq의 자료구조는 {거리가중치, 노드} 이다 -> 우선순위 큐에 따라 거리 weight를 오름차순으로 정렬하고 싶기 때문 
    pq.push({0, s});
    distances[s] = 0;

    while (!pq.empty()) {
        edge now = pq.top();
        pq.pop();
        int currentN = now.second;
        
        if (visited[currentN]) { continue; }

        visited[currentN] = true; // 현재 노드 방문 노드로 업데이트 

        for (int i = 0; i < alist[currentN].size(); i++) {
            edge tmp = alist[currentN][i];
            int nextN = tmp.first;
            int nextW = tmp.second;

            if (nextW + distances[currentN] < distances[nextN]) {
                distances[nextN] = nextW + distances[currentN];
                pq.push({distances[nextN], nextN});

            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (visited[i]) {
            cout << distances[i] << '\n';
        } else {
            cout << "INF" << '\n';
        }
    }
    return 0;
}
