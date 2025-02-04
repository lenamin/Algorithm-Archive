// 최소 스패닝 트리 
#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> parent;

 /// edge 정보 담은 구조체 
typedef struct Edge {
    int f, t, w; // from, to, weight
    bool operator > (const Edge& temp) const {
        return w > temp.w;
    }
} Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // edge list 

/// union find : a의 부모 찾는 함수 
int find(int a) { 
    if (parent[a] == a) {
        return a;
    } else {
        return parent[a] = find(parent[a]); // 이거 까먹었네,, 
    } 
}

/// union find : union 연산 수행 
void dounion(int a, int b) {
    a = find(a); // 각자의 부모노드 찾아서 
    b = find(b);

    if (a != b) {
        parent[b] = a; // 부모끼리 연결해서 합쳐줌 
    }
}

int main() {
    cin >> v >> e;

    parent.resize(v + 1);
    
    // parent 배열 초기화 
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    // 에지 정보 받기 
    for (int i = 0; i < e; i++) {
        int f, t, w;
        cin >> f >> t >> w;
        pq.push(Edge{ f, t, w });
    }

    int result = 0;
    int numEdge = 0;

    while(numEdge < (v - 1)) { // v-1 보다 edge 사용한 수가 적어지면
        Edge edge = pq.top();
        pq.pop();
        int f = edge.f;
        int t = edge.t;
        int w = edge.w;

        if (find(f) != find(t)) { // 크루스칼 -> 연결해도 사이클 안생기는지 확인
            dounion(f, t);
            result = result + w;
            numEdge++;
        }
    }

    cout << result;
}