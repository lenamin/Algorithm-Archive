// 치킨배달 (G5)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> city;

int main() {

    int n, k;
    cin >> n >> k;

    int answer = INT_MAX;
    city.resize(n + 1);
    vector<pair<int, int>> ch;
    vector<pair<int, int>> hs;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int m;
            cin >> m;
            city[i].push_back(m);
            if (m == 1) {
                hs.push_back({i, j}); // 집 좌표 
            } else if (m == 2) {
                ch.push_back({i, j}); // 치킨집 좌표 저장
            }
        }
    }

    // 1) 각 집마다 가장 가까운 치킨집과의 거리를 구한다 
    // 2) 최소값 변수를 두고, 최솟값이 갱신될 때마다 그 값을 업데이트한다
    // 3) 최종값을 반환한다 

    int ctotal = ch.size();
    int htotal = hs.size();

    vector<int> pick(ctotal, 0);
    

    // 조합 돌리기 위한 pick 배열 생성 
    for (int i = ctotal - k; i < ctotal; i++) {
        pick[i] = 1;
    }

    do {
        int total = 0;
        // 1을 기준으로 선택된 치킨집 인덱스 조합 처리 
        

        for (int i = 0; i < hs.size(); i++) { // 각 집 시작     
            int mdist = INT_MAX; // 집마다 최소 거리 초기화해야지 
            
            for (int j = 0; j < ch.size(); j++) {
                // 해당 집에서 각 치킨집마다의 거리를 구해서 최소거리를 구할거임 
                if (pick[j] == 1) {
                    int cdx = ch[j].first;
                    int cdy = ch[j].second;

                    int hdx = hs[i].first;
                    int hdy = hs[i].second;
                    
                    mdist = min(mdist, abs(cdx - hdx) + abs(cdy - hdy));
                }
            }
            
            total += mdist;
        }
        answer = min(answer, total);
        
    } while (next_permutation(pick.begin(), pick.end()));

    cout << answer << '\n';
}