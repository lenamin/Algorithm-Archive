#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<pair<int, int>>> m; // 장르 : [<재생횟수, 고유번호>]
    unordered_map<string, int> total; // 장르별 재생횟수 합 
    vector<pair<string, int>> tv;
    
    // 각 장르별 플레이수와 인덱스 저장 
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]].push_back({plays[i], i});
    }
    
    // 각 장르별 total plays 수 저장
    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
    }
    
    // 정렬 위해 벡터로 
    tv.assign(total.begin(), total.end());
    
    // 장르별 총합 내림차순 정렬 
    sort(tv.begin(), tv.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second > b.second;
    });
    
    for (auto t : tv) {
        string g = t.first; // 장르
        cout << t.second << endl;

        // 각 장르안에 있는 [{플레이수, 인덱스번호}] 정렬 
        // 플레이수 같으면 인덱스번호 오름차순 예외처리
        sort(m[g].begin(), m[g].end(), [](const pair<int, int> &a, const pair<int, int> &b) {
          if (a.first == b.first) {
              return a.second < b.second;
          } else {
              return a.first > b.first;
          }
        });
        
        // 각 장르에 하나만 있으면 하나만 추가
        if (m[g].size() == 1) {
            answer.push_back(m[g][0].second);
        } else {
            for (int i = 0; i < 2; i++) {
                answer.push_back(m[g][i].second);
            }
        }
    }
    return answer;
}