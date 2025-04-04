#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string init_name;
    
    // 3) 생각해야 할 예외 : A면 아예 그리로 커서 이동을 안해도 됨 
    
    // 1) 일단 글자수만큼의 A로 이뤄진 문자열 선언 및 초기화 
    int n = name.length();
    
    for (int i = 0; i < n; i++) {
        init_name += 'A';
    }
    
    
    // 2) "M" 기준으로 M보다 작으면 위로 (순차적으로) / 크면 아래로 (역순으로 : 그게 더 빠르니까)
    
    //조이스틱 이동횟수 카운트 (상하)
    for (int i = 0; i < n; i++) {
        
        if (name[i] <= 'N') {
            answer += alp.find(name[i]);
        } else {
            int idx = alp.find(name[i]);
            answer += abs(idx - 26);
        }
    }
    
    // 좌우 탐색 최소경로 찾기 
    int now = 0; // 현재 커서 위치 
    
    // answer += (abs(i - name.length()));   
    int mdist = n - 1;
    
    if (name.find('A') == string::npos) {
        answer += (n - 1);
    } else {
        for (int i = 0; i < n; i++) {
            int next = i + 1;

            while (next < n && name[next] == 'A') {
                next++; // 다음 A가 아닌 인덱스 값 구하기 
            }
            mdist = min(mdist, i + i + n - next);
            mdist = min(mdist, i + (n - next) * 2);
        }
        answer += mdist;       
    }
    
    
    return answer;
}