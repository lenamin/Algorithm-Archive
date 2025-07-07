#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    int totalFail = 0;
    
    vector<int> answer;
    vector<pair<double, int>> fail;
    map<int, int> mp; // {stage, failcnt (분자)}
    map<int, int> mp2; // {stage, 분모}
    
    
    // n : 총 스테이지 개수 
    // stages.size() : 플레이어 총 수 
    
    // stages 배열을 돌면서 (플레이어들의 현재 스테이지) -> 이걸 일단 sort()를 하는게 낫나? 

    
    int fcnt = 0;
    
    /*
    for (int i = 1; i <= N; i++) { // 각 stage를 돈다 

        for (int j = 0; j < stages.size(); j++) { // 각 stage에서 모든 플레이어들의 현재 
            int nows = stages[j];
            int stage = i;
            
            if (nows == stage) { 
                mp[stage]++;
            } 
            if (nows >= stage) {
                mp2[stage]++;
            }
        }
    }
    */
    
    vector<int> failCount(N + 2);
    vector<int> successCount(N + 2);
    
    // 일단 실패자 먼저 
    for (int s : stages) {
        if (s <= N) {
            failCount[s]++;
        }
    }
    
    int total = stages.size();
    
    for (int i = 1; i <= N; i++) {
        successCount[i] = total; // successCount의 초기값은 
        
        total -= failCount[i];
    }
    
    // for (int i = 1; i <= N; i++) {
    //     // cout << mp[i] << " / " << mp2[i] << '\n';
    //     if (mp2[i] == 0) { fail.push_back({0, i}); }
    //     else {
    //         double d = (double)mp[i] / (double)mp2[i];
    //         // cout << "d: " << d << '\n';
    //         fail.push_back({d, i});
    //     }
    // }
    
    for (int i = 1; i <= N; i++) {
        if (successCount[i] == 0) { fail.push_back({0, i}); }
        else {
            double d = (double)failCount[i] / (double)successCount[i];
            fail.push_back({d, i});
        }
    }
    
    sort(fail.begin(), fail.end(), [](const pair<double, int> &a, const pair<double, int> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    });
    
    for (auto f : fail) {
        answer.push_back(f.second);
    }
    
    return answer;
}