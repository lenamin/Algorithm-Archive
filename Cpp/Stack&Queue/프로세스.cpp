#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    // priorities : 우선순위 
    // priorities.size() : 프로세스 개수 
    // location : 몇 번째 실행되는지 알아야하는 인덱스 값 
    
    int answer = 0;
    typedef pair<int, int> myp; //  idx , priority 
    
    queue<myp> q;
    priority_queue<int, vector<int>, less<int>> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        
        int highest = pq.top();
        
        myp current = q.front();
        int cidx = current.first;
        int cp = current.second;
        
        q.pop();
        
        if (highest != cp) { // 지금꺼낸 우선순위가 가장 높은 우선순위가 아니면 
            q.push(current); // 큐 맨 뒤로 다시 보냄 
        } else if (highest == cp) {
            answer++;
            pq.pop(); // 실행했으니까 pq는 pop하고 
            
            if (location == cidx) {
                return answer;
            } else {
                continue;
            }
        }
    }
    return answer;
}

int main() {
    // 테스트 케이스 1
    vector<int> priorities1 = {2, 1, 3, 2};
    int location1 = 2;
    cout << "Test Case 1 Result: " << solution(priorities1, location1) << endl;  // 예상 결과: 1

    // 테스트 케이스 2
    vector<int> priorities2 = {1, 1, 9, 1, 1, 1};
    int location2 = 0;
    cout << "Test Case 2 Result: " << solution(priorities2, location2) << endl;  // 예상 결과: 5

    return 0;
}