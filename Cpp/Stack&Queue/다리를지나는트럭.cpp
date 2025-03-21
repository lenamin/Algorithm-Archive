#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 1차 시도 : 큐에 미리 truck_weights를 다 넣고 시작했다
    int answer = 0;
    int sum = 0;
    
    queue<int> q;
    int idx = 0;
    
    // queue는 동적 자료구조이기 때문에 내가 원하는 크기로 고정해서 쓸 수 없다 
    // 대신 원하는 크기만큼 초기값을 집어넣는 방식으로 다리 위 상태를 표현할 수 있다 
    
    
    while (idx < truck_weights.size() || !q.empty()) {
        
        if (idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }
        
        
        // 1초 흐름 
        answer++;
        
        if (q.size() == bridge_length) {
            int pre = q.front();
            sum -= pre;
            q.pop();    
        }
        
        int now = 0;
        
        if (idx < truck_weights.size()) {
            now = truck_weights[idx];
            
            if (sum + now <= weight) {
                    q.push(now); // 다리 위에 트럭 새로 올려 
                    sum += now; // 무게 더해 
                    idx++;    
                
            } else { // 만약 더한게 weight보다 더 크면 트럭 올라갈 수 없고, 시간만 흘러야 함 
                q.push(0);
            }
        } 
    }
    
    return answer;
    
}

int main() {
    
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    int result = solution(bridge_length, weight, truck_weights);
    cout << "다리를 건너는 데 걸린 총 시간: " << result << "초" << endl;

    return 0;
}