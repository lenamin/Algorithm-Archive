// 집합의 표현 복습 
#include <bits/stdc++.h>
using namespace std;

// 0일 때는 합집합 (1이 포함되어있는 집합과 b가 포함되어있는 집합 합침)
// 1 -> 두 원소가 같은 집합에 있는지 체크 


static vector<int> arr; // 대표노드가 저장되는 배열 
int find(int a);
void doUnion(int a, int b);
bool isSame(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;    
    cin >> n >> m;
    arr.resize(n+1);

    // 초기에 각 노드가 자기자신이 대표이다 
    for (int i = 0; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int f, a, b;
        cin >> f >> a >> b;
        if (f == 0) {
            doUnion(a, b);
        } else {
            if (isSame(a, b)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}

// 대표를 찾는다 
int find(int a)
{
    if (arr[a] == a) {
        return a;
    } else {
        return arr[a] = find(arr[a]);
    }
}

// 합집합을 수행한다
void doUnion(int a, int b) {
    // 대표 노드 찾아서 
    a = find(a);
    b = find(b);
   // 아 무조건 넣는게 아니라 대표가 다르면!!! 연결해줘야지 
   if (a != b) {
    arr[b] = a;
   }
}

// 같은 집합인지 체크한다 -> 대표가 같은지 체크한다
bool isSame(int a, int b)
{
    return find(a) == find(b);
}
