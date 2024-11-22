#include <iostream>
#include <vector>

using namespace std;

double solution()
{
  double n;
  double sum = 0;
  cin >> n;

  vector<double> scores(n);

  double max_sc;

  for (int i = 0; i < n; i++) {
    cin >> scores[i];
  }
  max_sc = scores[0];

  // 최댓값 구하기 
  for (int i = 0; i < scores.size(); i++) {
    sum += scores[i];
    if (max_sc < scores[i]) {
      max_sc = scores[i];
    }
  }
  return (sum * 100) / max_sc / n;
}

int main() 
{
  cout << solution();
}