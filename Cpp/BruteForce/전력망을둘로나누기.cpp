#include <bits/stdc++.h>
using namespace std;

int dfs(int v, vector<bool> visited, vector<vector<int>> ajl) {
    int cnt = 1;
    visited[v] = true;
    
    for (int i = 0; i < ajl[v].size(); i++) {
        int next_v = ajl[v][i];
        if (!visited[next_v]) {    
            cnt += dfs(next_v, visited, ajl);
            
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    // 1) 일단 입력을 트리 형태로 만들자 -> 인접 리스트 형태로 만드는게 좋겠지 
    // 2) 어떤 노드를 방문했을 때, 이걸 끊으면 각각의 노드 개수가 몇 개가 되는지를 체크? 
    // connected components 이용하면 되나? 
    
    vector<bool> visited(n + 1, false);
    
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> tmps; // 새로운 wires
        vector<vector<int>> new_ajl(n + 1); // 새로운 ajl
        
        // fill(tmps.begin(), tmps.end(), vector<int>(2));
        fill(visited.begin(), visited.end(), false);
        
        int sa, sb;
        
        // 간선 끊은 배열 만들기 
        for (int j = 0; j < wires.size(); j++) {
            if (j != i) {
                tmps.push_back(wires[j]);
            } else {
                sa = wires[i][0];
                sb = wires[i][1];
            }
        }
        
        // 끊은걸로 새로운 ajl 만들기
        for (auto tmp : tmps) {
            new_ajl[tmp[0]].push_back(tmp[1]);
            new_ajl[tmp[1]].push_back(tmp[0]);
        }
        
        int cnt_a = dfs(sa, visited, new_ajl);
        int cnt_b = dfs(sb, visited, new_ajl);
        
        
        if (answer > abs(cnt_a - cnt_b)) {
            answer = abs(cnt_a - cnt_b);    
        }
        
        // cout << "시작점이 " << sa << "일 때 cnt_a : " << cnt_a << '\n';
        // cout << "시작점이 " << sb << "일 때 cnt_b : " << cnt_b << '\n';
        // cout << " ---- " << '\n';
    }
    return answer;
}