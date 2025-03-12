#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> counts = {0, 0, 0};

    vector<int> first = {1, 2, 3, 4, 5}; // 1번 수포자
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};  // 2번 수포자
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 3번 수포자
    
    for (int i = 0; i < answers.size(); i++) {
       
        if (first[i % 5] == answers[i]) { 
            // 처음에 했던 실수 : answers[i % 5] 랑 비교해서 계속 같은 같은 비교했다!! 
            counts[0]++;
        } 
        
        if (second[i % 8] == answers[i]) {
           counts[1]++;
        }
    
        if (third[i % 10] == answers[i]) {
           counts[2]++;
       }
        
    }
    
    int mx = *max_element(counts.begin(), counts.end());
    // c++에는 *max_element의 인덱스를 찾는 함수가 따로 없고, 
    // distance를 이용하는 방법은 최대값이 같은 여러 개의 인덱스 구하기가 어려워서 
    // 다음과 같이 구현함 
    
    for (int i = 0; i < counts.size(); i++) {
        if (mx == counts[i]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

int main() {
    vector<int> s = solution({1, 2, 3, 4, 5, 1, 2, 3, 4, 5});

    for (int a : s) {
        cout << a << '\n';
    }
}