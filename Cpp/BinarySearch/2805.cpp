// 나무자르기 : Binary Search, Parametric Search 

#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> arr;


int main() {
    cin >> n >> t; 
    int tmp;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    // 일단 정렬 
    sort(arr.begin(), arr.end());

    // 이진탐색트리 인덱스 설정
    int start = 0;
    int end = *max_element(arr.begin(), arr.end());
    
    int answer = 0; 

    while (start <= end) {
        long long sum = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) { sum += arr[i] - mid; } // 현재 절단점으로 했을 때 얻을 수 있는 나무 길이 합 구하기 
        }

        if (sum >= t) {
            // 일단 조건 만족한다 -> 저장해놓고 더 잘라도 되는지 시도 
            answer = mid;
            
            start = mid + 1;

        } else {
            end = mid - 1;
        }
        // cout << sum << '\n';
    }

    cout << answer << '\n';
    
}