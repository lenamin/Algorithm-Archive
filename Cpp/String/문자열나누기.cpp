#include <bits/stdc++.h>

using namespace std;


int solution(string s) {
    int answer = 0;
    vector<string> arrs;
    
    int xcnt = 1;   
    int ocnt = 0;
    char x = s[0];
    
    for (int i = 1; i < s.size(); i++) {
        
        char o = s[i];
        
        if (x != o) { // 다음글자가 x랑 다르면 cnt 확인 
            ocnt++;
        
        } else { // 다음 글자랑 x랑 같으면 계속 세 
            xcnt++;
        
        }
        if (xcnt == ocnt) {
            answer++;
            if (i <= s.size() - 1) {
                x = s[i + 1];    
            }
            
            xcnt = 0;
            ocnt = 0;
        }
    }
    if (xcnt != ocnt) {
        answer++;
    }
    
    return answer;
}

int main() {
    string s = "banana";
    cout << solution(s) << endl; // Output: 3
    return 0;
}