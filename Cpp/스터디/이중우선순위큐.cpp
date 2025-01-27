#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream myString(input);
    string stringData;
    
    while (getline(myString, stringData, delimiter)) {
        result.push_back(stringData);
    }
    return result;
}

vector<int> solution(vector<string> operations) {
    int cnt = 0; // 전체 operation 횟수 제어
    int dmaxCnt = 0; // cnt가 하나일 때 뭘 남길지 체크하기 위한 변수1 
    int dminCnt = 0; // cnt가 하나일 때 뭘 남길지 체크하기 위한 변수2
    vector<int> answer;
    priority_queue<int> descPq; // 내림차순
    priority_queue<int, vector<int>, greater<int>> ascPq; // 오름차순
    
    for (auto o : operations) {
        vector<string> commands = split(o, ' ');
        string command = commands[0];
        int number = stoi(commands[1]);
        
        if (cnt == 0) { // 0이면 두 우선순위 큐 모두 초기화
            while (!descPq.empty()) descPq.pop();
            while (!ascPq.empty()) ascPq.pop();
        }
        
        if (command == "I") { 
            ascPq.push(number);
            descPq.push(number);
            cnt++;
        } else if (command == "D" && cnt != 0) {
            // 삭제 중 최솟값인 경우 
            if (number == -1) {
                ascPq.pop();
                cnt--;
                dminCnt--; // 최솟값을 삭제했을 때 dminCnt 값도 줄여준다

                // 최댓값인 경우 
            } else if (number == 1) {
                descPq.pop();
                cnt--;
                dmaxCnt--; // 반대도 마찬가지
            }
        }
    }
    
    if (cnt == 1) { // 하나만 남았을 때 min, max 어느쪽을 둘 다 push 해야하는지 체크 
        if (dminCnt < dmaxCnt) {
            answer.push_back(ascPq.top()); 
            answer.push_back(ascPq.top());    
        } else {
            answer.push_back(descPq.top()); 
            answer.push_back(descPq.top());    
        }
    } else if (cnt <= 0) {  // 0일 때 
        answer.push_back(0); 
        answer.push_back(0); 
    } else {
        answer.push_back(descPq.top());
        answer.push_back(ascPq.top());
    }
    
    return answer;
}