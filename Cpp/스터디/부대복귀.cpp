#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    // n : 총지역의 수 (노드개수)
    // roads : 두 지역을 왕복할 수 있는 길 정보를 담은 2차원 정수 배열 (엣지 정보)
    // sources : 각 부대원이 위치한 서로 다른 지역들을 나타내는 정수 배열 (각기 다른시작주소)
    // destination : 강철부대 지역 (목적지)
    // sources 원소 순서대로 복귀할 수 있는 최단시간 담은 배열 반환

    vector<int> d(n + 1, -1);
    // vector<bool> visited(sources.size() + 1, false);
    vector<int> answer;
    vector<vector<int>> ajlist(n + 1);
    
    // 인접리스트에 edge 정보 담는다 (각 노드를 잇는 길 정보담기)
    
    for (auto road : roads) {
        int v1 = road[0];
        int v2 = road[1];
        
        ajlist[v1].push_back(v2);
        ajlist[v2].push_back(v1);
    }
    
    //Reverse BFS 
    queue<int> q;
    q.push(destination);
    d[destination] = 0;
    
    while (!q.empty()) {    
        int now = q.front();
        q.pop();
        
        for (auto next : ajlist[now]) {
            if (d[next] != -1) { // 방문한적 있으면 패스 
                continue;
            }
            q.push(next); // 큐에 해당 노드 넣어준다
            d[next] = d[now] + 1; // 거리 정보 업데이트
        }
    }

    for (int s : sources) {
        answer.push_back(d[s]);
    }
    
    return answer;
}