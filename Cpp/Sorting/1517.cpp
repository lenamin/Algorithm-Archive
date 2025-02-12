// 버블 소트 
// O(nlogn) 시간복잡도가 걸리는 정렬 알고리즘으로 풀어야 함 

#include <bits/stdc++.h>
using namespace std;

int n; // 숫자 개수
vector<int> arr;
vector<int> tmp;
long result; // swap 횟수 저장, 문제 조건을 잘 보자,,,, 제발!! 

void merge_sort(int s, int e);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    result = 0;
    cin >> n;

    arr.resize(n);
    tmp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(0, n - 1);
    cout << result << '\n';
}

void merge_sort(int s, int e) {
    // 재귀함수 종료조건 
    if (s >= e) { return; }

    int m = (s + e) / 2;
    
    merge_sort(s, m);
    merge_sort(m + 1, e);

    for (int i = s; i <= e; i++) { // 이 범위는 굳이 전체일 필요가 없지. 그럼 O(n)이 되어서 시간초과 뜸. 지금 병합정렬 할 부분만! 
        tmp[i] = arr[i];
    }

    int k = s;
    int idx1 = s;
    int idx2 = m + 1;

    while (idx1 <= m && idx2 <= e) {
        if (tmp[idx1] > tmp[idx2]) {
            arr[k] = tmp[idx2];
            result += (idx2 - k); 
            // cout << "현재 result : " << result << '\n';
            k++;
            idx2++;
        } else {
            arr[k] = tmp[idx1];
            // result += (idx1 - k); 
            // cout << "현재 result : " << result << '\n';
            k++;
            idx1++;
        }
    }

    // 남아있는 애들 결과 배열에 넣어주기 
    while (idx1 <= m) {
        arr[k] = tmp[idx1];
        idx1++;
        k++;
    }
    while (idx2 <= e) {
        arr[k] = tmp[idx2];
        idx2++;
        k++;
    }
}