
#include <bits/stdc++.h>
using namespace std;

static vector<int> nodes;

// 경로압축 및 원소 a가 속한 집합의 대표를 찾는다  
int find(int a) {
    if (nodes[a] == a) { // 자기자신이 대표이면 대표 그대로 반환
        return a;
    } else {
        return nodes[a] = find(nodes[a]); // 경로압축을 적용해 a의 부모를 루트 노드로 직접 연결
    }
}

// a가 속한 집합과 b가 속한 집합을 합친다
void doUnion(int a, int b) {
    // find 연산
    a = find(a); // a의 루트노드를 찾고 a 업데이트 
    b = find(b); // b의 루트노드 찾고 b 업데이트
    if (a != b) { // 루트가 다르면 합쳐준다 
        nodes[b] = a;
    }
}

bool checkSame(int a, int b) { // 같은 집합인지 체크
    a = find(a);
    b = find(b);

    if (a == b) { return true; }  // 루트 노드가 같은지 체크 
    // return find(a) == find(b); // 한줄로도 가능 
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; // 원소개수, 질의개수 
    int f, p, k;
    cin >> n >> m;
    
    nodes.resize(n + 1);

    for (int i = 0; i <= n; i++) {
        nodes[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> f >> p >> k;
        if (f == 0) { 
            doUnion(p, k); 
        } else {
            if (checkSame(p, k)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}