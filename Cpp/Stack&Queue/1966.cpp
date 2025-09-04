#include <bits/stdc++.h>
using namespace std;

int k; // 총 테케 개수 
int n; // 문서의 개수 
int m; // 몇번째에 놓여있는지 궁금한 인덱스 
int cnt; 

int main() {
    // 가장 첫번재 우선순위 조사 
    // m번째 자리에 있는 수 target 으로 일단 꺼내놓고 
    // 첫번째 수의 우선순위보다 높은게 나머지에 하나라도 있으면 맨 뒤로 보내기 
    cin >> k;

    for (int i = 0; i < k; i++) {
        cnt = 0;
        cin >> n >> m;

        queue<pair<int, int>> q; // 우선순위가 있는 순서 
        priority_queue<int> pq;

        for (int j = 0; j < n; j++) {
            
            int tmp;
            cin >> tmp;

            q.push({j, tmp});
            pq.push(tmp);
        }
        
        while (!q.empty()) {
            int curMax = pq.top();
            auto now = q.front();
            
            q.pop();

            if (now.second == curMax) { // 출력
                
                pq.pop();
                cnt++;

                if (m == now.first) {
                    break;
                } 
            } else {
                q.push(now);
            } 
        }
        cout << cnt << '\n';
    }
}