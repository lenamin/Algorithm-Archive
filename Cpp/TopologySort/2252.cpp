// Topology Sort : 사이클이 없는 방향 그래프에서 사용할 수 있는 정렬 알고리즘 
// 노드를 선형적으로 정렬


// 1. 진입차수를 계산한다 -> indegree : 자기자신을 가리키는 에지의 개수 
// 2. 진입차수 배열에서 0인 노드를 선택 -> 이 노드를 큐에 저장한다 
// 3. 인접리스트에서 선택된 노드가 가리키는 노드들의 진입차수를 1씩 뺀다 (정렬을 이미 했으니까)
// 4. 큐가 빌 때 까지 반복하면 완료! 

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<int> indegree;

int main() {
    cin >> n >> m;
    arr.resize(n + 1);
    indegree.resize(n+1, 0);

    for (int i = 0; i < m; i++) {
        int e1, e2;
        cin >> e1 >> e2;
        arr[e1].push_back(e2);
        indegree[e2]++;
    }

    // for (int d : indegree) {
    //     cout << d << " ";
    // }

    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int next : arr[now]) {
            // 타겟 노드의 indgree 값 -- 
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}