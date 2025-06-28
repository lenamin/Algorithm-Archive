#include <bits/stdc++.h>
using namespace std;


// 슬라이딩 윈도우 연습 
// int main() {
//     vector<int> arr = {1, 2, 3, 4, 2, 1, 5};

//     // 이게 인덱스야 
//     int left = 0;
//     int right = 1;

//     int sum = 0;
//     int max_len = 0;

//     while (right < arr.size()) {
//         sum += arr[right];

//         while (sum > 10) {
//             sum -= arr[left];
//             left++;
//         }
//         max_len = max(max_len, right - left + 1);
//         right++;
//     }

    

//     cout << sum << '\n';
// }

int main() {
    int n;
    cin >> n;
    vector<int> fruits;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        fruits.push_back(tmp);
    }

    int right = 0, left = 0;
    int sum = 0;
    int answer = 0;

    int count[10] = {0};
    int kcnt = 0; // 현재 구간의 과일 개수 수

    while (right < n) {
        
        if (count[fruits[right]] == 0) {
            kcnt++; // 처음 들어오는 과일 종류니까 카운팅해야지 
        }
        count[fruits[right]]++; // 과일 개수 늘리기 

        while (kcnt > 2) {
            count[fruits[left]]--; // 우선 왼쪽끝의 과일 종류수 카운트를 1 줄이고 
            
            if (count[fruits[left]] == 0) {
                kcnt--; // 만약에 삭제 후 더 이상 없을 때 kcnt 업데이트하고 
            }

            left++; // 그러고나서 옮겨야지. 그래야 옮기기 이전의 값이 줄여지니까 
        }

        int now_length = right - left + 1;
        if (answer < now_length) {
            answer = now_length;
        }

        right++;
        
    }

    cout << answer << '\n';
}