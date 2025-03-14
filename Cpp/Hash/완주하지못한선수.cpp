#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> smp, cmp; 
    
    // map 초기화 
    for (string p : participant) {
        smp[p] = 0;
    }

    for (string c : completion) {
        cmp[c] = 0;
    }
    
    // 각 map 에 참가자, 완주자 숫자 세기 
    for (string p : participant) {
        smp[p]++;
    }
    
    for (string c : completion) {
        cmp[c]++;
    }
    
    // 숫자 다른거 answer 에 담기
    for (int i = 0; i < participant.size(); i++) {
        if (smp[participant[i]] != cmp[participant[i]]) {
            answer = participant[i];
        }
    }
    
    return answer;
}

string solution2(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> smp;

    // 참가자 추가 (숫자 세기)
    for (const string& p : participant) {
        smp[p]++;
    }

    // 완주자 제거
    for (const string& c : completion) {
        smp[c]--;
    }

    // 완주하지 못한 선수 찾기
    for (const auto& [key, value] : smp) {
        if (value > 0) return key;  // 0이 아닌 값이 있는 key가 완주하지 못한 선수!
    }

    return "";
}

int main() {
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"mislav", "stanko", "ana"}) << '\n';
    cout << solution2({"mislav", "stanko", "mislav", "ana"}, {"mislav", "stanko", "ana"});
}