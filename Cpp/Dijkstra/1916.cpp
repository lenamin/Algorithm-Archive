// 최소 비용 구하기 

#include <bits/stdc++.h>
using namespace std;

vector<int> distances;
typedef pair<int, int> edge;
vector<vector<edge>> ajlist; // 인접리스트 (idx(출발 vertex) : { to vertex , weight }
vector<bool> visited;
int v, e;

int dijkstra(int s, int e);

int main() {
    cin >> v >> e;

    ajlist.resize(v + 1);
    visited.resize(v + 1, false);
    distances.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int vertex, to, w;
        cin >> vertex >> to >> w;
        ajlist[vertex].push_back({to, w});
    }

    int s, e;
    cin >> s >> e;
    // 최단거리배열 초기화 (0, 무한대, 무한대)
    fill(distances.begin(), distances.end(), INT_MAX);

    cout << dijkstra(s, e) << '\n';
}

int dijkstra(int s, int e) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    // 다익스트라 출발 ~ 
    distances[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        edge now = pq.top();
        pq.pop();
        int currentV = now.second;

        if (!visited[currentV]) {
            visited[currentV] = true;

            for (auto next : ajlist[currentV]) {
                int nextV = next.first;
                int nextW = next.second;

                if (distances[nextV] > distances[currentV] + nextW) {
                    distances[nextV] = distances[currentV] + nextW;
                    pq.push({distances[nextV], nextV});
                }
            }
        }
    }
    return distances[e];
}