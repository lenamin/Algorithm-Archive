// 구간 합 구하기 3

#include <bits/stdc++.h>
using namespace std;

vector<long> tree; // segment tree 배열 

void initTree(int i); // tree 초기화하기 
long partSum(int s, int e); // s부터 e까지 구간의 합 구하기 
void updateVal(int idx, long val); // idx 번째의 값을 val로 update 

int main() {
    int n, m, k; // n : 개수, m : 수의 변경이 일어나는 횟수, k : 구간 합 구하는 횟수 
    cin >> n >> m >> k;
    
    int treeHeight = 0;
    int length = n;

    while (length != 0) {
        length /= 2;
        treeHeight++;
    }

    // 1) tree 사이즈 구하기 
    int treeSize = int(pow(2, treeHeight + 1));

    // 2) leftNodeStartIndex 구하기
    int leftNodeStartIndex = treeSize / 2 - 1;

    tree.resize(treeSize + 1, 0);
    
    
    // 3) tree 배열의 리프 노드 영역에 데이터 입력받기 

    for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + n; i++) {
        cin >> tree[i];
    }

    // 트리초기화하기 
    initTree(treeSize - 1);

    for (int i = 0; i < m + k; i++) {

        // a가 1이면 -> b번째 수를 c로 바꿈 
        // a가 2이면 -> b번째 수부터 c번째 수까지의 구간합 구하기 

        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            updateVal(leftNodeStartIndex + b, c);

        } else if (a == 2) {
            int start = b + leftNodeStartIndex;
            int end = c + leftNodeStartIndex;

            cout << partSum(start, end) << '\n';
        }

    }
    
}

void initTree(int i) { // 트리의 마지막 인덱스...가 i로 들어간다 
    while (i != 1) {
        tree[i / 2] += tree[i];
        i--;
    }
}

long partSum(int s, int e) {

    long psum = 0;

    while (s <= e) {
        if (s % 2 == 1) {
            psum += tree[s];
            s++;
        } 
        if (e % 2 == 0) {
            psum += tree[e];
            e--; // 시작인덱스 감소 
        }

        s /= 2;
        e /= 2;
    }
    return psum;
}

void updateVal(int idx, long val) {
    long diff = val - tree[idx];

    while (idx > 0) {
        tree[idx] = tree[idx] + diff;
        idx = idx / 2;
    }
}