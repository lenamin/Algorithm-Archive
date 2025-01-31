#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    int cnt = 1; // n 값을 미리 뽑는 경우의 수는 포함하고 시작
    
    int start = 1;
    int end = 1;
    int sum = 1;

    cin >> n;

    while (end != n) {
        if (sum == n) {
            cnt++;
            end++;
            sum += end;
        } else if (sum > n) {
            // 앞애껄 삭제해 
            sum -= start;
            start++;
        } else if (sum < n) {
            // sum이 더 작으면 뒤에꺼 추가해 
            end++;
            sum += end;
        }
    }

    cout << cnt << '\n';
}