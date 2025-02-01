#include <bits/stdc++.h>
using namespace std;

vector<int> req(4); // A, C, G, T 만족해야 하는 최소 개수 
vector<int> checkReq(4);
int cnt;
int ret;

void add(char c) {
    switch(c) {
        case 'A':
            checkReq[0]++;
            if (req[0] == checkReq[0]) {
                cnt++; // 만족시켰으면 cnt 증가 
            }
            break;
        case 'C':
            checkReq[1]++;
            if (req[1] == checkReq[1]) {
                cnt++; // 만족시켰으면 cnt 증가 
            }
            break;
        case 'G':
            checkReq[2]++;
            if (req[2] == checkReq[2]) {
                cnt++; // 만족시켰으면 cnt 증가 
            }
            break;
        case 'T':
            checkReq[3]++;
            if (req[3] == checkReq[3]) {
                cnt++; // 만족시켰으면 cnt 증가 
            }
            break;
    }
}

void remove(char c) {
    switch(c) {
        case 'A':
            if (req[0] == checkReq[0]) {
                cnt--; // 원래 만족했지만, 지워야하면 cnt 감소
            }
            checkReq[0]--;
            break;
        case 'C':
            if (req[1] == checkReq[1]) {
                cnt--;
            }
            checkReq[1]--;
            break;
        case 'G':
            if (req[2] == checkReq[2]) {
                cnt--;
            }
            checkReq[2]--;
            break;
        case 'T':
            if (req[3] == checkReq[3]) {
                cnt--;
            }
            checkReq[3]--;
            break;
    }
}

int main() {
    int s, p; // DNA 문자열 길이, 부분 문자열 길이 
    string full; // DNA 문자열
    
    cin >> s >> p;
    cin >> full; 
    
    vector<int> secrets(p); // 부분문자열이 들어갈 벡터

    for (int i = 0; i < 4; i++) {
        cin >> req[i];
        if (req[i] == 0) { // 요구조건 받다가 특정 문자 최소 요구조건이 0이면 자동으로 그 조건이 충족되는거니까 cnt +1 해줌 
            cnt++;
        }
    }
    
    // 초기윈도우 (0~p-1)
    for (int i = 0; i < p; i++) {
        add(full[i]); // checkReq에 넣은것 확인    
    }

    if (cnt == 4) { ret++; } // 첫번째 윈도우가 네 가지 조건 모두 충족되었는지 확인 

    for (int i = p; i < s; i++) {
        int j = i - p;
        add(full[i]);
        remove(full[j]);

        if (cnt == 4) {
            ret++;
        }
    }

    cout << ret << '\n';
    
}