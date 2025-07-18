#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    // 부르면 앞에 있는 애랑 자리바꿈 
    map<string, int> mp;
    vector<string> newp = players;
    
    for (int i = 0; i < players.size(); i++) {
        mp[players[i]] = i;
    }
    
    for (string s : callings) {
        int rank = mp[s];

        if (rank - 1 >= 0) {
            swap(newp[rank], newp[rank - 1]);
            swap(mp[newp[rank]], mp[newp[rank - 1]]);
        }
    }
    
    for (string n : newp) {
        answer.push_back(n);
    }
    return answer;
}

int main() {
    vector<string> players = {"mumu", "soe", "poe", "kai", "mine"}; 
    vector<string> callings = {"kai", "kai", "mine", "mumu"};
    vector<string> result = solution(players, callings);
    for (const string& player : result) {
        cout << player << " ";
    }                                                                                               
    cout << endl; // Output: "soe poe kai mumu mine"
    return 0;
}       