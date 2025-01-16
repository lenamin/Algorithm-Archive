// 11047 : 동전 개수의 최솟값 구하기
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; // 입력개수, 목표금액
    int cnt = 0;

    vector<int> coins(n + 1);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // 끝에서부터 돌면서 4700보다 작은게 나오면 조합 만들기
    for (int i = n - 1; i >= 0; i--) {
        if (coins[i] <= k) {
            cnt += k / coins[i]; // 필요한 동전 숫자 계산해서 더함

            int mod = k % coins[i]; // 나눈 나머지 (남는거) k에 업데이트해서 반복 
            if (mod == 0) {
                break;
            } else {
                k = mod;
                continue;
            }
        }
    }
    cout << cnt << '\n';
}