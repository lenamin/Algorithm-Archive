#include <bits/stdc++.h>
using namespace std;

vector<char> vows = {'A', 'E', 'I', 'O', 'U'};
int answer= 0;
int cnt = 0;

void dfs(string now, string word) {
    if (now == word) {
        answer = cnt;
        return;
    }
    if (now.length() == 5) { return; }
    
    for (int i = 0; i < 5; i++) {
        cnt++;
        dfs(now + vows[i], word);
        if (answer != 0) { return; }
    }
}

int solution(string word) {
    string str;
    
    dfs(str, word);
    return answer;
}