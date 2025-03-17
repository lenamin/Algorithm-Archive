#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // n : 전체 학생 수
    // lost : 체육복을 잃어버린 학생의 번호 
    // reserve : 여벌의 체육복을 가지고 있는 학생의 번호 
    
    // 1) 우선 여벌의 체육복을 가지고 있는 학생들부터 처리하자. 
    
    // 일단 정렬을 먼저 해야 한다 
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    set<int> lset(lost.begin(), lost.end());
    set<int> rset(reserve.begin(), reserve.end());
    vector<int> onlyLost;
    set<int> onlyReserve;
    
    set_difference(lset.begin(), lset.end(), rset.begin(), rset.end(), inserter(onlyLost, onlyLost.begin()));
    set_difference(rset.begin(), rset.end(), lset.begin(), lset.end(), inserter(onlyReserve, onlyReserve.begin()));
        
    int br = 0; // onlyLost 중에서 체육복 빌린 애 
        
    for (auto o : onlyLost) {
        if (find(onlyReserve.begin(), onlyReserve.end(), o - 1) != onlyReserve.end()) {
            auto it = find(onlyReserve.begin(), onlyReserve.end(), o - 1);
            onlyReserve.erase(it);
            br++;
        } else {
            if (find(onlyReserve.begin(), onlyReserve.end(), o + 1) != onlyReserve.end()) {
                auto it = find(onlyReserve.begin(), onlyReserve.end(), o + 1);
                onlyReserve.erase(it);
                br++;
            } else {
                continue;
            }
        }
    }
    
    answer = n - onlyLost.size() + br;
    
    return answer;
}

int main() {
    cout << solution(5, {5, 3}, {4, 2}) << '\n';
}