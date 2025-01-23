#include <bits/stdc++.h>
using namespace std;

char arr[5][15];

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            // cout << "(i, j) = " << i << ", " << j << endl;
            if (arr[i][j] != '\0') { // != NULL은 포인터변수에서만 쓸 수 있다 
                cout << arr[i][j];
            }
            
        }
    }
    return 0;
}