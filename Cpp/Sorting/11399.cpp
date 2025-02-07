// 삽입정렬 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> sum(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 삽입정렬 
    for (int i = 0; i < n; i++) {
        int insert_point = i;
        int insert_value = arr[i];

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                insert_point = j + 1;
                break;
            }
            if (j == 0) {
                insert_point = 0;
            }
        }
        for (int j = i; j > insert_point; j--) {
            arr[j] = arr[j-1];
        }
        arr[insert_point] = insert_value;
    }
     
    sum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + arr[i];
    }

    int s = 0;

    for (int i = 0; i < n; i++) {
        s += sum[i];
    }

    cout << s;
}