// 단계별
// 과제 안 내신 분..? 

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr(30);

    for (int i = 1; i <= 28; i++) {
        int n;
        cin >> n;
        arr[n] = n;
    }

    for (int i = 1; i <= 30; i++) {
        // arr[i] == 0 으로 조건검사하면 초기화된 값도 나오기 때문에 정확하지 않음!
        if (arr[i] != i) {  
            cout << i << '\n';
        }
    }
}