#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int cnt = 0;
    
    // 66.7 점 코드 
//     for (int i = 1; i <= n; i++) {
//         int sum = 0;
//         for (int j = i; j <= n; j++) {
//             sum += i; // 여기서 i 넣어서 틀린 코드! 
//             if (sum == n) {
//                 cnt++;
//                 break;
//             } else if (sum > n) {
//                 break;
//             }
//         }
//     }
    
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j;
            if (sum == n) {
                cnt++;
                break;
            } else if (sum > n) {
                break;
            }
        }
    }
    return cnt;
}