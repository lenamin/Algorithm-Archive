#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int d; // 삭제할 노드 입력받기 
int answer;
void dfs(int a);

int main() {
    int n;
    cin >> n; // 노드개수 입력받음 

    tree.resize(n + 1);
    visited.resize(n + 1);

    int root = 0;

    // 트리 자료구조 만들기 
    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a; // 이게 부모노드인거잖아. 그럼 부모 노드의 밑에 들어가도록 해야지. 
        if (a != -1) {
            tree[a].push_back(i);
            tree[i].push_back(a);
        } else {
            root = i;
        }
    }

    cin >> d;

    if (d == root) {
        cout << 0 << '\n';
    } else {
        dfs(root);
        // 그럼 루트에서 시작해서 m을 만나면 멈춘다. 그리고 만나는 리프노드를 센다. 
        cout << answer << '\n';    
    }
}

void dfs(int a) {
    visited[a] = true;
    int cnt = 0;

    for (auto next : tree[a]) {
        if (!visited[next] && next != d) {
            cnt++;
            dfs(next);
        }
    }

    if (cnt == 0) {
        answer++;
    }

}