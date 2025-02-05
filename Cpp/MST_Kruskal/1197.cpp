#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

typedef struct Edge {
    int f, t, w;
    bool operator > (const Edge& tmp) const {
        return w > tmp.w;
    }
} Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int find(int a) {
    if (parent[a] == a) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}

void dounion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    parent.resize(v + 1);

    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        int f, t, w;
        cin >> f >> t >> w;
        pq.push(Edge{ f, t, w });
    }

    int numEdge = 0;
    int result = 0;

    while (numEdge < v - 1) {
        Edge edge = pq.top();
        pq.pop();

        if (find(edge.f) != find(edge.t)) { // 사이클 형성 안하면 
            dounion(edge.f, edge.t);
            numEdge++;
            result += edge.w;
        }
    }
    cout << result << '\n';
}