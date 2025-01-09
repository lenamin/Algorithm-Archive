// 여행가자 

#include <bits/stdc++.h>
using namespace std;

static vector<int> parent;
int city[204][204];
static vector<int> route;

int find(int a) {
    if (parent[a] == a) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}

void doUnion(int a, int b) {
    a = find(a);
    b = find(b); // 대표노드 가져와서 

    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 인접행렬을 탐색하면서 연결될 때 마다 union 연산을 수행한다     
    int n, m; 
    cin >> n; // 도시의 수
    cin >> m; // 여행계획에 속한 도시의 수

    parent.resize(n+1);
    route.resize(m+1);
    string s;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> city[i][j]; // 이 작업은 왜 배열에서만 가능할까?? 
        }
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> route[i];
    }

    // 자기자신을 대표노드로 초기화 
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // city 탐색하면서 1이면 해당 집합에 넣어준다 (doUnion) 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == 1) {
                doUnion(i, j);
            }
        }
    }
    // 여행 route 탐색하면서 연결되어있는지 체크 
    // 중간에 false 나오면 NO 출력, 그 외에는 모두 YES 
    bool isConnected = true;

    // int index = find(route[1]);

    // for (int i = 2; i <= m; i++) {
    //     if (index != find(route[i])) {
    //         cout << "NO" << '\n';
    //         isConnected = false;
    //         break;
    //     }
    // }

    for (int i = 2; i <= m; i++) {
        int p = route[i];
        int k = route[i-1];
        
        if (find(p) != find(k)) {

            cout << "NO" << '\n';
            isConnected = false;
            break;
        } 
        // 왜 이렇게 하면 값이 틀리게 나올까? 
        // if (!isSame(i, find(route[i]))) {
        //     isConnected = false;
        //     break;
        // }
    }
    //*/
    if (isConnected) {
        cout << "YES" << '\n';
    }
}