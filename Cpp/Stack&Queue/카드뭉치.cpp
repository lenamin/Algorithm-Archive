#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    queue<string> q1;
    queue<string> q2;
    queue<string> q3;
    
    for (string s : cards1) {
        q1.push(s);
    }
    
    for (string s : cards2) {
        q2.push(s);
    }
    
    for (string s : goal) {
        q3.push(s);
    }
    
    while (!q3.empty()) {
        string s = q3.front();
        
        if (!q1.empty() && s == q1.front()) {
            q3.pop();
            q1.pop();
        } else if (!q2.empty() && s == q2.front()) {
            q3.pop();
            q2.pop();
        } else {
            break;
        }
    }
    
    if (q3.empty()) {
        answer = "Yes";
    } else {
        answer = "No";
    }
    
    return answer;
}

int main() {
    vector<string> cards1 = {"i", "drink", "water"};
    vector<string> cards2 = {"want", "to"};
    vector<string> goal = {"i", "want", "to", "drink", "water"};
    
    cout << solution(cards1, cards2, goal) << endl; // Output: Yes
    
}