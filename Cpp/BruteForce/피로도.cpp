#include <bits/stdc++.h>

using namespace std;
int answer = 0;
int cnt = 0;

void dfs(int f, int dsize, vector<bool>& visited, vector<vector<int>> dungeons) {
    for (int i = 0; i < dungeons.size(); i++) {
        int mf = dungeons[i][0];
        int cf = dungeons[i][1];

        if (!visited[i] && f >= mf) {
            cnt++;
            visited[i] = true;
            answer = max(answer, cnt);
            dfs(f - cf, i + 1, visited, dungeons);
            
            cnt--; // true로 못간 경우 백트랙킹해주는 코드 !!!!!!!! ---- ** 
            visited[i] = false;
        } 
    }
}   


int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    
    dfs(k, 0, visited, dungeons);
    
    return answer;
}

/*
	1.	아직 안 간 던전을 찾는다.
	2.	입장 가능하면 간다 (visited[i] = true)
	3.	탐색 끝나고 돌아오면 원래 상태로 돌려놓는다 → 백트래킹
	4.	모든 경로를 다 시도해서, 가장 많이 방문한 개수(answer)를 구한다.
*/
