#include <bits/stdc++.h>
using namespace std;

int n; // 1차원 스크린의 크기
int m; // 바구니가 차지하는 칸 
int j; // 떨어지는 사과의개수 
int cnt;

int main() {
    cin >> n >> m;
    cin >> j;

    int start = 1;
    int end = m;

    for (int i = 0; i < j; i++) {
        int k; // 과일이 떨어지는 위치 
        cin >> k;
        
        // 바구니 초기 위치는 1~m까지겠지 
        int move = end - start + k;

        if (k < start || k > end) {
            int move = min(abs(k - end), abs(k - start));
            cnt += move;

            if (k < start) {
                start -= move;
                end -= move;
            } else {
                start += move;
                end += move;
            }
        }
    }
    cout << cnt << '\n';
}