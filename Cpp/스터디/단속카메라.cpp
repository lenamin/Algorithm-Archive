// 단속카메라 
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int c; // 마지막 카메라 설치 좌표
    
    int k = routes.size(); // 차량 대수 
    
    // 2차원 벡터 두번째 요소 기준으로 오름차순 정렬 
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
       return a[1] < b[1]; 
    });
    
    c = routes[0][1]; // 첫번째 카메라 설치
    answer++;
    
    for (int i = 1; i < k; i++) { // 첫번째는 이미 설치했으므로 두번째 요소부터 순회
        if (routes[i][0] <= c && routes[i][1] >= c) { // 카메라가 범위내에 이미 있으면 패스
            continue;
        } else {
            c = routes[i][1]; // 그렇지 않으면 추가 설치
            answer++;
        }
    }
    return answer;
}