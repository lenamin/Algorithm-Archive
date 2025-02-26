#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> ajlist; // 인접리스트 
vector<bool> visited; // 방문했는지 정보저장
vector<int> distances; // 최소비용 업데이트할 배열 

int dijkstra(int s, int e);

int main() {
    int v, e;
    cin >> v >> e; // 정점 개수, 엣지 개수 입력받아 

    ajlist.resize(v+1);
    visited.resize(v+1, false);
    distances.resize(v+1, INT_MAX);

    for (int i = 0; i < e; i++) {
        int v, to, w;
        cin >> v >> to >> w;
        ajlist[v].push_back({to, w});
    }

    int start, end;
    cin >> start >> end;

    cout << dijkstra(start, end) << '\n';
}

int dijkstra(int s, int e) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    
    pq.push({0, s}); // {weight, start vertex} -> wieght 기준으로 pq 최소힙으로 만들거니까 
    distances[s] = 0;

    while (!pq.empty()) {
        edge now = pq.top();
        pq.pop();

        int nowW = now.first;
        int nowV = now.second;

        if (!visited[nowV]) {
            visited[nowV] = true; // 최소힙이니까 weight가 제일 작은게 꺼내진게 분명함 -> nowV까지는 최소비용 확정된 것! 

            for (auto next : ajlist[nowV]) { // ajlist[nowV] 현재 vertex 에서부터 갈 수 있는 곳의 weight 모두 순회할 수 있지 
                int nextW = next.second;
                int nextV = next.first;                
                
                // visited[nextV] = true; // 이건 여기서 나오면 안됨 -> visited 배열은 최소비용이 확정되었을 때만 true로 해줄 수 있는 것 

                if (distances[nextV] > distances[nowV] + nextW) {
                    distances[nextV] = distances[nowV] + nextW;
                    // pq에 다시 넣어주는걸 까먹었네 
                    pq.push({distances[nextV], nextV});
                }

            }
        }
    }
    return distances[e];
}