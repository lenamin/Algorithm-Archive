#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> arr(n+1, vector<bool>(n+1, false));
    
    for (auto r : results) {
        int win = r[0];
        int loose = r[1];
        
        arr[win][loose] = true;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (arr[s][k] && arr[k][e]) {
                    arr[s][e] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
       int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] || arr[j][i]) {
                cnt++;
            }
        }
        if (cnt == n-1) {
            answer++;
        }
    }
    
    return answer;
}