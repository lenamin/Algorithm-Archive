#include <bits/stdc++.h>
using namespace std;

int n, q;
long long f[21], s[21];
bool visited[21] = {false};

int main() {
    cin >> n >> q;
    f[0] = 1;

    // 팩토리얼 계산 미리 해놓기
    for (int i = 1; i <= n; i++) {
        f[i] = f[i-1] * i;
    }

    if (q == 1) { // 소문제 1 일 때 
        long long k;
        cin >> k;

        for (int i = 1; i <= n; i++) {
            for (int j = 1, cnt = 1; j <= n; j++) {
                if (visited[j]) {
                    continue; 
                }

                if (k <= cnt * f[n-i]) {
                    k -= ((cnt - 1) * f[n-i]);
                    s[i] = j;

                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << s[i] << " ";
        }
        cout << '\n';
    }

    else {
        long long k = 1;

        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            long long cnt = 0;

            for (int j = 1; j < s[i]; j++) {
                if (visited[j] == false) {
                    cnt++;
                }
            }

            k += cnt * f[n-i];
            visited[s[i]] = true;
        }
        cout << k << '\n';
    }
}