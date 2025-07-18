#include <bits/stdc++.h>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    set<char> skipset;
    
    for (int i = 0; i < skip.size(); i++) {
        skipset.insert(skip[i]);
    }
    
    for (int i = 0; i < s.size(); i++) {
        int nc = s[i];
        
        int cnt = 0;
        
        while (cnt < index) {
            nc++;
            if (nc > 'z') { nc = 'a'; }
            if (skipset.count(nc)) { continue; } // set에서 nc가 있는지 없는지 판단할 때 
            cnt++;
        }
        answer.push_back(nc);
    }
    
    return answer;
}

int main() {
    string s = "aukks";
    string skip = "wbqd";
    int index = 5;
    
    cout << solution(s, skip, index) << endl; // Output: "happy"
    
    return 0;
}