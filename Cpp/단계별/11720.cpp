#include <iostream>
#include <vector>

using namespace std;

int solution()
{
  int sum = 0;
  int n;
  cin >> n;

  string str_num;

  cin >> str_num;

  for (auto n: str_num)

    sum += (n - '0');
  
  return sum;
}

int main() 
{
  cout << solution();
}