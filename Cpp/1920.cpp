#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1) 일단 정렬 
// 2) 이진탐색 ~~ 

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  // 1) 첫번째 입력 
  cin >> n;

  vector<int> numbers(n);

  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  // 이진탐색 전 미리 정렬해두고 
  sort(numbers.begin(), numbers.end());

  // 이진탐색 시작 
  // target 정해 
  // start, end 선언해 
  // start가 end보다 작으면 계속 반복할건데 
    // 중간값 찾아  (중간인덱스, 중간값 모두!)
    // target이 중간값보다 작으면  --> 왼쪽에서 찾을거니까 end 인덱스를 중간인덱스 - 1로 수정 
    // target이 중간값보다 크면 --> 오른족에서 찾을거니까 start 인덱스를 mid + 1로 수정해 
    // 모두 아니면 찾은것 -> while 탈출 

  cin >> m; 

  for (int i = 0; i < m; i++) {
    bool isFind = false;
    int target;
    cin >> target;
    
    int start = 0;
    int end = numbers.size() - 1;
    
    while (start <= end) {
      int midIndex = (start + end) / 2;
      
      // if (target == numbers[midIndex]) {
      //   isFind = true;
      //   break;
      // } else if (target < numbers[midIndex]) {  
      //   end = midIndex - 1;
      // } else if (target > numbers[midIndex]) {
      //   start = midIndex + 1;
      // }

      if (target < numbers[midIndex]) {
        end = midIndex - 1;
      } else if (target > numbers[midIndex]) {
        start = midIndex + 1;
      } else {
        isFind = true;
        break;
      }
    }
  // isFind ? cout << 1 << '\n' : cout << 0 << '\n';
    if (isFind) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
}