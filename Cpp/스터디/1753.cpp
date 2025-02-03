// 최단경로 (다익스트라)
#include <bits/stdc++.h>
using namespace std;

int v, e, s; // vertex 개수, edge 개수, 시작정점
typedef pair<int, int> edge; // { weight, to }
vector<vector<edge>> ajlist; // ajlist[index] = [{ weight, to}, ...]
vector<int> distances; // 각 vertex당 업데이트할 최소 거리
priority_queue<edge, vector<edge>, greater<edge>> pq; // 오름차순 정렬 그런데 이제 edge 타입의... 
vector<bool> visited; // 방문여부 체크 배열 

int main() {
    cin >> v >> e;
    cin >> s;

    // 각 자료구조들 공간 만들어주기 
    ajlist.resize(v + 1);
    distances.resize(v + 1);
    visited.resize(v + 1, false);
    fill(distances.begin(), distances.end(), INT_MAX);

    for (int i = 0; i < e; i++) {
        int f, t, w; // from vertex, to vertex, weight 
        cin >> f >> t >> w;

        ajlist[f].push_back({w, t}); //f 에서 t로 갈 때 가중치가 w다는 정보 저장 
    }

    pq.push({0, s}); // 시작점으로부터 방문 시~작 
    distances[s] = 0; // 자기자신은 0이니까 

    while (!pq.empty()) {
        edge now = pq.top(); // 하나 꺼내
        int nowV = now.second;
        int nowW = now.first;

        pq.pop();
        if (visited[nowV]) { continue; } // 이미 방문했으면 패스 
        visited[nowV] = true; // 방문처리 해주고

        for (int i = 0; i < ajlist[nowV].size(); i++) { // nowV의 인접노드들을 방문
            edge next = ajlist[nowV][i]; 
            int nextV = next.second;
            int nextW = next.first;

            if (distances[nowV] + nextW < distances[nextV]) { // 다음 방문하는 노드로 가는 가중치가 기존 다음 노드의 가중치보다 작으면
                distances[nextV] = distances[nowV] + nextW; // 그 값을 업데이트 
                pq.push({distances[nextV], nextV});
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

}