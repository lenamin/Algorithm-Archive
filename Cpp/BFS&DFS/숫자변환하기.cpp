#include <bits/stdc++.h>

using namespace std;

int solution(int x, int y, int n) {
    // x : 시작값 
    // y : 목표값 
    // n : 더할 수 있는 값 
    queue<pair<int, int>> q; // { 현재숫자, 연산횟수}
    int answer = 0;
    
    vector<bool> visited(1000004, false); // index가 이미 만들어놓은 숫자, 방문여부 
    
    // 연산종류 : +n, x2, x3 종류가 있어. 
    // 이 중에 최소한의 연산으로 y를 만들 수 있는걸 찾는다... 
    
    q.push({x, 0});
    visited[x] = true;
    
    
    while (!q.empty()) {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (curr == y) { return cnt; }
        
        for (int next : { curr + n, curr * 2, curr * 3}) {
            if ((next <= y) && !visited[next]) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }

    return -1;
}