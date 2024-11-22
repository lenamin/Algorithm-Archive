#include <iostream>
#include <vector>

using namespace std;

void solution()
{

  int n;
  int q;
  cin >> n >> q;
  
  vector<int> sums(n+1, 0);
  
  for (int i = 1; i < n + 1; i++) {
    int temp;
    cin >> temp;
    sums[i] = temp + sums[i-1];
  }
  
  for (int i = 0; i < q; i++) {
    int b, e;
    cin >> b >> e;
    cout << sums[e] - sums[b-1] << '\n';
  }
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);    
  cout.tie(NULL);

  solution();
}