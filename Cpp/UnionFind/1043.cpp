// 거짓말
#include <bits/stdc++.h>
using namespace std;

int h, p; // 사람의 수, 파티의 수
int t; // 진실을 아는 사람의 수
static vector<int> parent;
static vector<int> trues;
static vector<vector<int>> parties;

    // 입력
    // 8 5 // 사람의 수, 파티의 수
    // 3 1 2 7 // 진실을 아는 사람의 수와 그 사람들의 번호 (0명이면 번호 주어지지 X)
    // 2 3 4 // 첫번째 파티 사람 수와 번호 
    // 1 5 // 두번째
    // 2 5 6 // 세번쨰
    // 2 6 8 // 네번째
    // 1 8 // 다섯번째

int find(int a) {
    if (parent[a] == a) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}

void doUnion(int a, int b) {
    a = find(a);
    b = find(b);

    // 대표가 다르면 직접 연결
    if (a != b) { 
        parent[b] = a;
    }
}

int main() {

    cin >> h >> p;
    cin >> t; // 진실을 아는 사람
    trues.resize(t);
    parties.resize(p);
    parent.resize(h+1);
    
    for (int i = 0; i < t; i++) {
        cin >> trues[i];
    }

    // 자기자신으로 초기화 
    for (int i = 0; i <= h; i++) {
        parent[i] = i;
    }


    if (t > 0) {
        int repT = trues[0];
        for (int i = 1; i < t; i++) {
          doUnion(repT, trues[i]);
        }
    }



    // 파티정보 받기 
    for (int i = 0; i < p; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            int tmp;
            cin >> tmp;
            parties[i].push_back(tmp);
        }
    }


    // 파티 배열 쭉 돌면서 같은 파티 사람들 한 그룹으로 만들어주기 
    for (int i = 0; i < p; i++) {
        int rep = parties[i][0];

        for (int j = 1; j < parties[i].size(); j++) {
            doUnion(rep, parties[i][j]);
        }
    }
    int cnt = 0;
    // 진실을 아는 사람 -> 1, 2, 7 (trues 배열)

    for (int i = 0; i < p; i++) {
        int rep = parties[i][0];
        bool isPossible = true;

        for (int j = 0; j < trues.size(); j++) {
            if (find(rep) == find(trues[j])) {
                isPossible = false;
                break;
            } 
        }
        if (isPossible) {
            cnt += 1;
        }
    }

    cout << cnt << '\n';

}