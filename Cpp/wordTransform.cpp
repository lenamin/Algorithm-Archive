#include <bits/stdc++.h>
using namespace std;

bool isTransform(string s1, string s2) {
    int diff = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            diff++;
        }
    }
    // cout << "diff: " << diff << endl;
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    unordered_set<string> visited;

    if (find(words.begin(), words.end(), target) == words.end()) { return 0; }

    q.push({begin, 0});
    visited.insert(begin);

    while (!q.empty()) {
        string curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (curr == target) {
            return cnt;
        }

        for (const string& word : words) {
            if (visited.find(word) == visited.end() && isTransform(curr, word)) {
                q.push({word, cnt + 1});
                visited.insert(word);
            }
        }
    }
    return 0;
}

int main() {
    cout << solution("hit", "zfd", {"hot", "dot", "dog", "lot", "log", "cog"}) << endl;
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << endl;
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << endl;

}