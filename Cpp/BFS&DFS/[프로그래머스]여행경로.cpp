#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, vector<string>> mp;
vector<int> visited;
vector<string> answer;
vector<vector<string>> tks;
bool found = false;

void dfs(string from) {
    
    if (answer.size() == tks.size() + 1) { 
        found = true;
        return; 
    }
    
    for (int i = 0; i < tks.size(); i++) {
        if (!visited[i] && from == tks[i][0]) {    
            visited[i] = 1;
            answer.push_back(tks[i][1]);
            
            
            dfs(tks[i][1]);
            if (found) return; 
            answer.pop_back();
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    
    tks = tickets;

    for (int i = 0; i < tickets.size(); i++) {
        for (int j = 0; j < tickets[i].size(); j++) {
            string key = tickets[i][0];
            mp[key].push_back(tickets[i][1]);   
        }   
    }
    
    visited.resize(tickets.size(), 0);
    
    answer.push_back("ICN");
    dfs("ICN");
    
    return answer;
}