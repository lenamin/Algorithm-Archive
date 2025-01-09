#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq; // 우선순위 큐 활용 
    long long answer = 0;
    
    for (auto w : works) { // 일단 작업량 모두 우선순위큐에 넣기
        pq.push(w);
    }
    
    while (n != 0 && !pq.empty()) { // 남은 시간만큼 순회 && 우선순위 큐 순회하면서 값 조정 
        int k = pq.top();
        pq.pop();
        n--; 
        
        if (k != 1) { // 꺼낸 값이 1이면 조정할 필요없으니까 
            pq.push(k-1);
            // cout << k-1 << " ";
        }
    }
    
    while (!pq.empty()) {
        int k = pq.top();
        answer += k * k;
        pq.pop();
    }
    
    return answer;
}