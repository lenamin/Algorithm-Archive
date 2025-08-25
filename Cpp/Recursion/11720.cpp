#include <bits/stdc++.h>
using namespace std;

int n = 0;
int cnt = 0;

void hanoi(int k, int from, int aux, int to) {
    if (k == 1) { 
        cout << from << " " << to << '\n'; 
        return; 
    }

    hanoi(k - 1, from, to, aux);
    cout << from << " " << to << '\n';
    hanoi(k - 1, aux, from, to);
}

int main() {

    // 초기 의문 : 각 장대의 위치와 원판이 어디있는지를 구현해야하나? -> 아님 
    // 1) hanoi(k, from, aux, to) 에서 일단 제일 큰 원판을 위해서 n-1을 치워줘야 하니까 
        // 1-1) n-1개를 aux로 옮긴다 
        // hanoi(k - 1, from, to, aux);
        // print(from -> to)  // 이제 다 치웠으니까 제일 큰 원판 치움 
        // 1-2) aux 에 있는거 다시 to 로 옮김 
        // hanoi(k - 1, aux, from, to);

    cin >> n;
    cout << int(pow(double(2), double(n)) - 1) << '\n';
    hanoi(n, 1, 2, 3);

}