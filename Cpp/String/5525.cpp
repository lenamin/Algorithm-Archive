// 5525. IOIOI 

#include <bits/stdc++.h>
using namespace std;

int n, m; // n은 I들 사이에 있는 0의 개수, m은 문자열 char 개수 
int answer;

int main() {
    cin >> n >> m;

    string target = "I";
    string s;
    cin >> s;

    // 찾아야하는 반복되는 문자열 구하기 
    for (int i = 1; i <= n; i++) {
        target.append("OI");
    }

    // cout << target << '\n';
        
    int i = 0;
    while (i < m - 1) {
        if (s[i] == 'I') {
            int cnt = 0;
            while (i + 2 < m && s[i + 1] == 'O' && s[i + 2] == 'I') {
                cnt++;
                if (cnt >= n) answer++;
                i += 2;
            }
            if (cnt == 0) {
                i++;
            } else {
                i -= 1;
            }
            cnt = 0;
            
        } else {
            i++;
        }
        
    }

    cout << answer << '\n';
}