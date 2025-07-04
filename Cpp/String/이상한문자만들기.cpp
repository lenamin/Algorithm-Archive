#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0; 
    
    
    /*
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') { continue; }
        mp[i] = s[i];
    }

    
    for (int i = 0; i < mp.size(); i++) {
        char c = mp[i];
        
        if (i % 2 == 0) {
            answer.push_back(toupper(c));
        } else {
            answer.push_back(tolower(c));
        }
    }
    */
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            idx = -1;
        }
        char c = s[i];
        if (idx % 2 == 0) { 
            answer.push_back(toupper(c));
        } else {
            answer.push_back(tolower(c));
        }
        idx++;
    }
    
    return answer;
}