#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    
    for (int n : numbers) {
        strs.push_back(to_string(n)); 
    }
    
    sort(strs.begin(), strs.end(), [](string a, string b) {
        return b + a < a + b;
    });
    
    // while (strs[0] == "0" && strs.size() != 1) {
    //     strs.erase(strs.begin(), strs.begin() + 1);
    // } // 굳이 이렇게 어렵게 while 문 안돌아도 돼! 
    
    if (strs[0] == "0") { // 첫자리가 0인 경우는 뒷 자리도 0인 경우밖에 없으니까 바로 "0" 반환하면 된다 
        return "0";
    }
    
    for (string s : strs) {
        answer += s;
    }
    return answer;
}

int main() {
    cout << solution({0, 0, 0}) << '\n'; // 0
    cout << solution({30, 21, 9}) << '\n'; // 93021 
}