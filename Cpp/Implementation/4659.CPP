// 비밀번호 발음하기 

#include <bits/stdc++.h>
using namespace std;

string s;

bool check1st(string s) {
    if (s.find('a') != string::npos || 
        s.find('e') != string::npos || 
        s.find('i') != string::npos || 
        s.find('o') != string::npos || 
        s.find('u') != string::npos) {
            return true;
        } else { return false; }
}

bool check2nd(string s) {
    string moeum = "aeiou";

    int mcnt = 0;
    int jcnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (moeum.find(s[i]) != string::npos) {
            // 이럼 모음이지
            mcnt++;
            jcnt = 0;
        } else {
            jcnt++;
            mcnt = 0;
        }

        if (mcnt == 3 || jcnt == 3) {
            return false;
        }
    }
    return true;
}

bool check3rd(string s) {
    int cnt = 0;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1] && !(s[i] == 'e' || s[i] == 'o')) {
            return false;
        }
    }
    return true;
}

int main() {
    // 비밀번호 규칙

    while (true) {
        cin >> s;
        if (s == "end") break;

        if (check1st(s) && check2nd(s) && check3rd(s)) {
                cout << "<" << s << ">" << " is acceptable." << '\n';
            } else {
                cout << "<" << s << ">" << " is not acceptable." << '\n';
        }
        
    }
}