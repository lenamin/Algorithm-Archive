// 게임 개발하기 
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr; // 그래프 저장할 인접리스트 
vector<int> indegree; // 진입차수 
vector<int> times; // 건물생산시간 
vector<int> ans; // 정답배열 

int main() {
    int n; // 지어야하는 건물 종류 수 
    cin >> n;

    arr.resize(n + 1);
    times.resize(n + 1);
    indegree.resize(n + 1);
    ans.resize(n + 1);

    // 데이터 입력 
    for (int i = 1; i <= n; i++) {
        int h; // 건물 생산시간 
        cin >> h;
        times[i] = h; // 건물 생산시간 배열에 정보 추가 

        while (true) {
            int pre;
            cin >> pre;
            if (pre == -1) break;

            // -1이 아니면 할 작업들 1) 진입차수 카운트 2) 노드 연결 
            indegree[i]++;
            arr[pre].push_back(i);
        }
    }
    // 데이터 입력 끝 ~ 이제 진입차수 돌면서 건물 지어야 하는 순서대로 시간 계산해보자 

    // 디버깅용 
    // for (auto i : indegree) 
    // {
    //     cout << i << " ";
    // }
    
    // 큐 생성한다 
    // 진입차수에서 0인 노드 먼저 큐에 넣고 방문한다. 
    
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // for (int i = 1; i <= arr[now].size(); i++) {
        //     // next node = i
        //     indegree[i]--;
        //     ans[i] = max(ans[i], ans[now] + times[now]);
        //     if (indegree[i] == 0) {
        //         q.push(i);
        //     }
        // }

        for (int i : arr[now]) {
            // next node = i
            indegree[i]--;
            ans[i] = max(ans[i], ans[now] + times[now]);
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] + times[i] << '\n';
    }
}