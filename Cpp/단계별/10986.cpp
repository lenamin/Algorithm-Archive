#include <iostream>
#include <vector>

using namespace std;

void solution()
{
  // 1) n, m 입력받는다 
  // + numbers, sums 배열 선언한다 
  // 2) numbers 배열 입력받는다 + 입력받으면서 각 부분합 배열을 구한다 
  // 3) 부분합 배열의 값을 m으로 모듈러 연산을 한 값을 받는다 ->
  //    이걸 sums 배열에 업데이트 한다 
  // 4) 변경된 sums 배열에서 원소값이 0인 개수를 count 한다 
  // 5) sums 배열에서 원소값이 같은 인덱스 개수를 센다 -> 같은거 찾으면 되겠지 

  int n,m;
  long count = 0;
  cin >> n >> m;

  vector<long> sums(n, 0);
  vector<long> counts(m, 0);

  cin >> sums[0];

  for (int i = 1; i < n; i++) {
    int number;
    cin >> number;
    sums[i] = sums[i-1] + number;
  }

  // 모듈러 연산 값을 sums에 넣기 
  for (int i = 0; i < n; i++) {
    int temp = sums[i] % m;
    if (temp == 0) {
      count++;
    }
    counts[temp]++;
  }

  for (int i = 0; i < m; i++) {
    if (counts[i] > 1) {
      count = count + (counts[i] * (counts[i] - 1) / 2);
    }
  }
  cout << count << '\n';
}

int main() 
{
  solution();
}