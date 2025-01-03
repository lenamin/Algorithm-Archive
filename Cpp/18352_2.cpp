// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> ad;
// vector<int> visited;
// vector<int> ans;

// void bfs(int a) {
//     queue<int> q; // 큐 선언 
//     q.push(a); // 큐에 시작값 넣고 
//     visited[a]++;  // 현재 노드 방문처리 

//     while (!q.empty()) {
//         int currNode = q.front();
//         q.pop();
        
//         for (auto adj : ad[currNode]) {
//             if (visited[adj] == -1) {
//                 // q.push(adj);
//                 visited[adj] = visited[currNode] + 1;   
//                 q.push(adj);
//             }
//         }
//     }
// }

// int main() {
//     int v, e, d, s;
//     cin >> v >> e >> d >> s;

//     ad.resize(v+1);
//     visited.resize(v+1, -1);

//     for (int i = 1; i <= e; i++) {
//         int v1, v2;
//         cin >> v1 >> v2;
        
//         ad[v1].push_back(v2); // 단방향 그래프
//     }

//     bfs(s);
    
//     for (int i = 0; i <= v; i++) {
//         if (visited[i] == d) {
//             ans.push_back(i);
//         }
//     }

//     if (ans.empty()) {
//         cout << -1 << '\n';
//     } else {
//         sort(ans.begin(), ans.end());
//         for (int a : ans) {
//             cout << a << '\n';
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
vector<int> visited;
vector<int> ans;

void bfs(int a) {
    queue<int> q;
    q.push(a);
    visited[a]++; // 방문처리

    while (!q.empty()) {
        int k = q.front();
        q.pop();

        for (int i : arr[k]) {
            if (visited[i] == -1) {
                q.push(i);
                visited[i] = visited[k] + 1;
            }
            
        }
    }
}

int main() {
    int v, e, d, s;
    cin >> v >> e >> d >> s;

    arr.resize(v + 1);
    visited.resize(v + 1, -1);

    for (int i = 0; i < e; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        arr[t1].push_back(t2);
    }

    bfs(s);

    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == d) {
            ans.push_back(i);
        }
    }

    if  (ans.empty()) {
        cout << -1 << '\n';
    } else {
        sort(ans.begin(), ans.end());
        for (int a : ans) {
            cout << a << '\n';
        }
    }
}