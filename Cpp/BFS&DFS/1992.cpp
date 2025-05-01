// 쿼드트리 
#include <bits/stdc++.h>
using namespace std;

int arr[64][64];

bool check(int x, int y, int size) {
    int cmp = arr[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (cmp != arr[i][j]) {
                // 다른게 나오면 사등분을 할거야 
                // 여기서 재귀호출하는게 맞나? 
                return false;
            }
        }
    }
    return true;
}

void divide(int x, int y, int size) {
    if (check(x, y, size)) {
        cout << arr[y][x];
        return;
    } 

    cout << '(';
    int half = size / 2;

    divide(x, y, half);
    divide(x + half, y, half);
    divide(x, y + half, half);
    divide(x + half, y + half, half);

    cout << ')';
}

int main() {
    int n;
    cin >> n;

    // 입력 완료 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    divide(0, 0, n);

}