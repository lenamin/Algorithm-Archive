// 재귀함수를 활용한 완전탐색
#include <bits/stdc++.h>
using namespace std;

// n, n개의 자연수 주어지고 
//  몇 개를 골라서 합에 대해 mod 11 연산했을 때 나오는 수 중 가장 큰 수 구하기 

int n, mx, ret, cnt;
const int mod = 11;
vector<int> numbers;

void go(int idx, int sum) {
    cout << "go(" << idx << ", " << sum << ") 호출됨!!" << endl;
    if (idx == n) {
        // cout << "=== End of branch: sum = " << sum << ", sum % mod = " << sum % mod << " ===" << endl;
        ret = max(ret, sum % mod);
        cnt++;
        return;
    }
    // 현재 숫자 포함하는 경우
    // cout << "포함하여 재귀다시 : numbers[" << idx << "] = " << numbers[idx] << endl;
    go(idx + 1, sum + numbers[idx]);
    
    // cout << "포함안함 : numbers[" << idx << "] = " << numbers[idx] << endl;
    go(idx + 1, sum);
}

int main() {
    cin >> n;
    numbers.resize(n+1);

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        numbers[i] = tmp;
    }

    go(0, 0);
    cout << "결과값: " << ret << endl;
}