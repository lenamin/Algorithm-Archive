// Merge Sort 로 구현해보기 

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tmp;
void merge_sort(int s, int e);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    arr.resize(n);
    tmp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
}

void merge_sort(int s, int e) {
    // P1. 재귀 종료 조건 추가해야함 

    // s == e 이면 배열 크기 1인 것 -> 이미 정렬된 상태임 
    if (s == e) return; 

    int m = (s + e) / 2;

    // 재귀함수 형태로 구현할거야 
    merge_sort(s, m);
    merge_sort(m + 1, e);

    for (int i = s; i <= e; i++) {
        tmp[i] = arr[i]; // 임시배열에다가 arr 잠시 넣어놓고
    }

    // 두 그룹 병합하기 
    int k = s; // 결과 배열에 넣을 idx 위치 
    int idx1 = s; // 앞그룹 시작점
    int idx2 = m + 1; // 뒤쪽그룹 시작점 

    while (idx1 <= m && idx2 <= e) {
        if (tmp[idx1] > tmp[idx2]) {
            arr[k] = tmp[idx2];
            k++;
            idx2++;
        } else if (tmp[idx1] < tmp[idx2]) {
            arr[k] = tmp[idx1];
            idx1++;
            k++;
        }
    }
    // 남은 데이터 정리를 어떻게 해야되지???
    // 한쪽 그룹이 모두 선택된 경우에 남은 데이터 그대로 배열에 넣어주기 

    // idx1이 아직 끝에 도달하지 못했을 때 
    while (idx1 <= m) {
        arr[k] = tmp[idx1];
        k++;
        idx1++;
    }

    while (idx2 <= e) {
        arr[k] = tmp[idx2];
        k++;
        idx2++;
    }
}