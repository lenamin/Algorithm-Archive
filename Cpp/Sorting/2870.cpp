#include <bits/stdc++.h>
using namespace std;

vector<string> arrs;

bool cmp(string &a, string &b) {
    // 1. 길이 다르면 길이 짧은 게 더 작은 숫자 
    if (a.size() != b.size()) return a.size() < b.size();

    // 2. 길이 같을 때는 사전순으로 비교 
    return a < b;
}


int main() {
    int n;
    cin >> n;

    // 1. 일단 숫자를 찾으면 넣는다 

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string ts;

        for (char c : s) {
            
            if (isdigit(c)) {
                if (!ts.empty() && ts == "0") {
                    ts = c;
                } else {
                    ts.push_back(c);
                }

            } else if (!isdigit(c) && ts != "") {
                arrs.push_back(ts);
                ts = ""; // ts 초기화 (문자 만났으니까)
            }
        }

        if (!ts.empty()) {
            arrs.push_back(ts);
            ts = "";
        }
    }
    sort(arrs.begin(), arrs.end(), cmp);

    for (string s : arrs) {
        cout << s << '\n';
    }
}