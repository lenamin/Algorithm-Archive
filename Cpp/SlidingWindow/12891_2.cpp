#include <bits/stdc++.h>
using namespace std;

vector<int> req(4);
vector<int> myv(4);
int cnt, ret; // cnt : 4번 다 채우는지 체크 / ret : 몇 개가 최종적으로 cnt가 4인지

void add(char c) {
    switch (c) {
        case 'A':
            myv[0]++;
            if (req[0] == myv[0]) { 
                cnt++;
            }
            break;
        case 'C':
            myv[1]++;
            if (req[1] == myv[1]) { 
                cnt++;
            }
            break;
        case 'G':
            myv[2]++;
            if (req[2] == myv[2]) { 
                cnt++;
            }
            break;
        case 'T':
            myv[3]++;
            if (req[3] == myv[3]) { 
                cnt++;
            }
            break;
    }
}

void remove(char c) {
    switch (c) {
        case 'A':
            if (req[0] == myv[0]) {
                cnt--;
            }
            myv[0]--;
            break;
        case 'C':
            if (req[1] == myv[1]) {
                cnt--;
            }
            myv[1]--;
            break;
        case 'G':
            if (req[2] == myv[2]) {
                cnt--;
            }
            myv[2]--;
            break;
        case 'T':
            if (req[3] == myv[3]) {
                cnt--;
            }
            myv[3]--;
            break;
    }
}

int main() {
    int f, p;
    string str;

    cin >> f >> p;
    cin >> str;

    for (int i = 0; i < 4; i++) {
        cin >> req[i];
        if (req[i] == 0) { cnt++; }
    }

    for (int i = 0; i < p; i++) {
        // 처음 자른 슬라이딩 윈도우 부분에 대해서 myv 구현 
        add(str[i]);
    }

    if (cnt == 4) { ret++; }

    
    for (int i = p; i < f; i++) {
        int j = i - p;
        add(str[i]);
        remove(str[j]);

        if (cnt == 4) {
            ret++;
        }
    }

    cout << ret << '\n';
    
}