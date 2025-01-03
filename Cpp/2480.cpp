#include <bits/stdc++.h>
using namespace std;

/*
같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다.
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.
*/

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    
    // 첫번째 두번째 숫자 같을 때
    if (arr[0] == arr[1]) {
        // 첫번째 세번째도 같으면 세개 모두 동일 (모두 동일한 경우는 여기서 다 해결된 것))
        if (arr[0] == arr[2]) {
            cout << 10000 + arr[0] * 1000 << '\n';
        } else {
            cout << 1000 + arr[0] * 100 << '\n';
        }
    } else if (arr[0] == arr[2]) {
        if (arr[0] != arr[1]) {
            cout << 1000 + arr[0] * 100 << '\n';
        }
    } else if (arr[0] != arr[1]) {
        if (arr[1] == arr[2]) {
            cout << 1000 + arr[1] * 100 << '\n';
        } else if (arr[1] != arr[2]) {
            sort(arr.begin(), arr.end());
            cout << arr[2] * 100 << '\n';
        }
    }
}