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

/** 문제 헷갈린 부분 정리
문제 핵심
- 큐에서 프로세스를 하나씩 꺼내며, 다른 프로세스 중 더 높은 우선순위가 있으면 → 다시 큐 뒤로.
- 그렇지 않으면 실행하며, 내가 원하는 프로세스가 몇 번째로 실행되는지 구해야 함.

1. 우선순위 큐(priority_queue)로 첫 시도 함 
	- 사용 가능하지만, 단독 사용은 X 
	- priority_queue는 가장 높은 우선순위 확인용으로만 사용해야 하고, 프로세스 순서를 유지하기 위해 queue도 필요함.
    - 순서대로 실행해야하는데 순서 보장이 안되니까!! 

2. 우선순위 큐에서 pop() 시기
	- 비교 전에 pq.pop() 하면 안 됨!
	- pq.top()으로 비교만 하고, 실제로 실행할 때만 pq.pop() 해야 우선순위 손실 없음.

3. 큐에서 pop() 중복 실수
	- 한 프로세스를 꺼냈는데 q.pop()을 두 번 한 경우 → 큐가 밀림
	- 프로세스 꺼내고 나면 한 번만 q.pop()

4. answer++ 시기
	- 우선순위 안 맞을 때도 증가시킴 → 실행 순서 왜곡
	- 프로세스를 실행할 때만 answer++

5. 정답 체크 기준 혼동
	- target == cp 로 비교하면 같은 우선순위의 다른 프로세스일 수 있음
	- 반드시 cidx == location 으로 비교해서 정확히 내가 찾는 프로세스 확인해야 한다

*/