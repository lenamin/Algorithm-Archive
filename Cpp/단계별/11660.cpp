#include <iostream>
#include <vector>

using namespace std;

void solution()
{
  int n, q;

  cin >> n >> q;
  vector<vector<int>> numbers(n+1, vector<int>(n+1, 0));
  vector<vector<int>> sums(n+1, vector<int>(n+1, 0));

  // 원본 배열 받아서 저장하기 
  for (int i = 1; i < n+1; i++) {
    for (int j = 1; j < n+1; j++) {
      cin >> numbers[i][j];
      sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + numbers[i][j];
    }
  }

  // q만큼 돌면서 질의계산하기 
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int result = sums[x2][y2] - sums[x1-1][y2] - sums[x2][y1-1] + sums[x1-1][y1-1];
    cout << result << '\n';
  }
}

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  solution();
  return 0;
}