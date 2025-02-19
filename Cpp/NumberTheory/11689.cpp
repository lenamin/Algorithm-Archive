// 오일러 피 함수 
// 1부터 n까지의 수 중 n과 서로소인 개수를 구하는 함수 
// -> n의 약수를 포함하는 수들은 제외해야 함 
#include <bits/stdc++.h>
using namespace std;

long result;
long n; 

int main() {

    cin >> n;
    result = n; // 전체개수로 초기화 

    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result = result - result / i;
            // 소인수이면 result에서 i의 배수들을 한번에 제거함 (개수가 한번에 줄어들게)
            
            while (n % i == 0) { // 소인수 i가 n에 여러번 포함되어 있을 수 있으니까 더 이상 없을 때 까지 계속 제거해주기 
                n /= i;
            }
        }
    }

    // 마지막에 소수가 남아있을 경우 -> 자기자신 빼줌 
    if (n > 1) {
        result = result - result / n;
    }

    cout << result;
}