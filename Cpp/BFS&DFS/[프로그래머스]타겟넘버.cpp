#include <bits/stdc++.h>

using namespace std;

int tg = 0;
vector<int> arr;
int cnt = 0;

void dfs(int index, int sum) {
    
    if (index == arr.size()) { // arr.size() - 1으로 검사하면 마지막 유효숫자를 검사하지 않고 넘어가는 것!! 그니까 아예 더 이상 탐색할 수 없을 때가 되었을 때 종료조건 검사 
        if (sum == tg) {
            cnt++;
        }
    }
    
    int nxt_idx = index + 1;
    
    if (nxt_idx <= (arr.size())) {
        
        dfs(nxt_idx, sum + arr[index]);
        dfs(nxt_idx, sum - arr[index]);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    tg = target;
    
    arr.resize(numbers.size());
    arr = numbers;
    
    dfs(0, 0);
    answer = cnt;
    return answer;
}
