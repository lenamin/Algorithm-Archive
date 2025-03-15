//최솟값 찾기 

#include <bits/stdc++.h>
using namespace std;

vector<long> tree; // segment tree 배열 

void initTree(int i);
int getMin(int s, int e);

int main() {

    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int treeHeight = 0;
    int length = n;

    while (length != 0) {
        length /= 2;
        treeHeight++;
    }

    // 1) tree 사이즈 구하기 
    int treeSize = int(pow(2, treeHeight + 1));

    // 2) leftNodeStartIndex 구하자  : leaf 노드들 (가장 마지막 깊이))
    int leftNodeStartIndex = treeSize / 2 - 1; 


    tree.resize(treeSize + 1, 0);
    fill(tree.begin(), tree.end(), LONG_MAX);

    // tree 배열의 리프 노드에 데이터 입력시켜주기 

    for (int i = leftNodeStartIndex + 1; i <= n + leftNodeStartIndex; i++) {
        cin >> tree[i];
    }

    initTree(treeSize - 1);

    for (int i = 0; i < q; i++) {
        long s, e;
        cin >> s >> e;
        s = s + leftNodeStartIndex;
        e = e + leftNodeStartIndex;

        cout << getMin(s, e) << '\n';
    }
}

// tree 의 부모노드들 넣기 
void initTree(int i) {
    while (i != 1) {
        if (tree[i/2] > tree[i]) {
            tree[i/2] = tree[i];
        }
        i--;
    }
}

int getMin(int s, int e) {
    long Min = LONG_MAX;

    while (s <= e) {
        if (s % 2 == 1) {
            Min = min(Min, tree[s]);
            s++;
        }
        s = s / 2;

        if (e % 2 == 0) {
            Min = min(Min, tree[e]);
            e--;
        }

        e = e / 2;
    }
    return Min;
}