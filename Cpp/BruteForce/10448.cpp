#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tri(45);

    // 삼각수 배열 미리 만들기
    for (int j = 1; j <= 1000; j++) {
        tri[j] = j * (j + 1) / 2;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bool status = false;

        for (int j = 1; j <= 44; j++) {    
            for (int k = 1; k <= 44; k++) {
                for (int m = 1; m <= 44; m++) {
                    if (tri[j] + tri[k] + tri[m] == x) {
                        status = true;
                        break;
                    }
                }
            }
            
        }
        cout << (status ? 1 : 0) << '\n';

    }
}