#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    
    sort(d.begin(), d.end());
    
    for (int i = 0; i < d.size(); i++) {
        // cout << "sum: " << sum << ", " << "answer: " << answer << '\n';
        sum += d[i];
        if (sum > budget) { break; }
        answer++;
        
    }
    
    return answer;
}