#include <bits/stdc++.h>

using namespace std;

int zcnt = 0;
int bcnt = 0;

string eraseZero(string s) { // 0 지우기
    string ns = "";
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != '0') {
            ns += c;
        } else {
            zcnt += 1;
        }
    }
    return ns;
}


string makeOneBinary(int a) {
    if (a == 1) { return "1"; }
    
    int m = a / 2;
    
    if (a % 2 == 1) {    
        return makeOneBinary(m) + '1';
    } else if (a % 2 == 0) {
        return makeOneBinary(m) + '0';
    }
}


string makeBin(int a) {
    bcnt += 1;
    return makeOneBinary(a);
}

vector<int> solution(string s) {
    vector<int> answer;
    
    string nc = s; 
    string ns = "";
    
    while (true) {
        
        ns = eraseZero(nc);
        nc = makeBin(ns.size());   

        if (nc == "1") {
            break;
        } 
    }
    
    answer.push_back(bcnt);
    answer.push_back(zcnt);
    
    return answer;
}

int main() {
    string s = "110010101001";
    vector<int> result = solution(s);
    
    cout << "Number of iterations: " << result[0] << endl;
    cout << "Number of zeros removed: " << result[1] << endl;
    
    return 0;
}