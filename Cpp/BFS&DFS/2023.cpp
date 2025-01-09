#include <iostream>
#include <vector>

using namespace std;

static int digit;
bool is_prime(int n);
void dfs(int n, int current_digit);

int main()
{
  cin >> digit; // 자릿수 입력받기 

  dfs(2, 1);
  dfs(3, 1);
  dfs(5, 1);
  dfs(7, 1);

}

bool is_prime(int n)
{
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) { return false; }
  }
  return true;
}

void dfs(int n, int current_digit)
{
  if (current_digit == digit) {
    if (is_prime(n)) {
      cout << n << '\n';
    }
    return;
  }

  for (int i = 1; i < 10; i++) {
    // if (n % 2 == 0) { // 이거 없어도 되나,,? 위에서 체크했으니까 
    //     continue;
    // } 
    if (is_prime(n * 10 + i)) {
        dfs(n * 10 + i, current_digit + 1);
    }
  }
}