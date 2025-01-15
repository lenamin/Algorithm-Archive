/* 두번째 코드
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> scores) {
    
    int answer = 1;
    int wa = scores[0][0]; // 완호의 근무태도점수
    int wc = scores[0][1]; // 완호의 동료평가점수
    int ws = wa + wc;
    vector<int> sums; // 점수합계 배열
    
    // 1. 인센티브 받지 못하는 경우 먼저 
    for (int i = 1; i < scores.size(); i++) {
        if ((wa < scores[i][0]) && (wc < scores[i][1])) { 
            return -1;
        }
    }
    
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) { return a[1] > b[1]; }
        return a[0] > b[0];
    });
    
    int maxC = -1;
    
    for (const auto &score : scores) {
        if (score[1] < maxC) continue; 
        maxC = max(maxC, score[1]);
        sums.push_back(score[0] + score[1]);
    }
        
    sort(sums.rbegin(), sums.rend());
    
    for (int s : sums) {
        if (ws < s) {
            answer++;
        }
    }
    return answer;
}


    /*
    // 1. 인센티브 받지 못하는 경우 먼저 
    for (int i = 1; i < scores.size(); i++) {
        if ((wa < scores[i][0]) && (wc < scores[i][1])) { 
            return -1;
        }
    }
    
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) { return a[1] > b[1]; }
        return a[0] > b[0];
    });
    
    int maxC = -1;
    
    for (const auto &score : scores) {
        if (score[1] < maxC) {
            if (score[0]) { continue; } 
            else if (score[0] )
        } else if (score[1] > maxC) {
            maxC = max(maxC, score[1]);
            sums.push_back(score[0] + score[1]);    
        }
    }
    
    // 2. 전체 등수 매기기 전 인센티브 못받는 사람 flag false로 
    /* 시간초과코드
    for (int i = 1; i < scores.size(); i++) {
        int a = scores[i][0]; // 근무태도점수
        int c = scores[i][1]; // 동료평가점수
        
        for (int j = 1; j < scores.size(); j++) {
            if (a < scores[j][0] && c < scores[j][1]) {
                flag[i] = false;
            }  
        }
    }
    */ 
    
    // for (bool f : flag) {
    //     cout << f << " ";
    // }
    
    // scores 벡터 재정의 
    
    
//     for (int i = 0; i < scores.size(); i++) {
//         if (flag[i]) {
//             newScores.push_back(scores[i]);
//         }
//     }

    
    // 3. 점수합계 배열에 각 합 저장하기
//     for (int i = 0; i < newScores.size(); i++) {
//         int cs = newScores[i][0] + newScores[i][1]; // 동료의 점수 합 
//         sums.push_back(cs);
//     }
        /*
    sort(sums.rbegin(), sums.rend());
    
    for (int s : sums) {
        cout << s << " ";
    }
    for (int s : sums) {
        if (ws < s) {
            answer++;
            // cout << "등수 하나 올라감 answer" << answer << endl;
        }
    }
*/

// 최적화 한 코드
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> scores) {
    
    int answer = 1;
    int wa = scores[0][0]; // 완호의 근무태도점수
    int wc = scores[0][1]; // 완호의 동료평가점수
    int ws = wa + wc;
    vector<int> sums; // 점수합계 배열
    vector<bool> flag(scores.size(), true);
    
     for (int i = 1; i < scores.size(); i++) {
        if ((wa < scores[i][0]) && (wc < scores[i][1])) { 
            return -1;
        }
    }
    
    sort(scores.begin() + 1, scores.end());
    
    // 2. 전체 등수 매기기 전 인센티브 못받는 사람 flag false로 
    
    for (int i = 1; i < scores.size(); i++) {
        int a = scores[i][0]; // 근무태도점수
        int c = scores[i][1]; // 동료평가점수
        
        if (ws >= a + c) { continue; } // 원호 합이 더 높으면 어차피 검사할 필요도 없다 (순위에 영향 미치지 않으므로)
        
        for (int j = i + 1; j < scores.size(); j++) {
            if (a < scores[j][0] && c < scores[j][1]) {
                flag[i] = false;
                break;
            } 
        }
    }
    
    // flag true로 표시된 것만 sums에 넣기
    for (int i = 0; i < scores.size(); i++) {
        if (flag[i]) {
            sums.push_back(scores[i][0] + scores[i][1]);
        }
    }
    
    sort(sums.rbegin(), sums.rend());
    
    // 등수계산
    for (int s : sums) {
        if (ws < s) {
            answer++;
        }
    }
    
    return answer;
}