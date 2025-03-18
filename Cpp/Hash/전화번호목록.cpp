#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    set<string> st;
    
    for (string p : phone_book) {
        st.insert(p);
    }
    
    for (string p : phone_book) {
        
        string pf = "";
        
        for (char c : p) {
            pf += c;
            
            if (pf == p) continue;
            if (st.find(pf) != st.end()) {
                return false;

            }
        }
        
    }
    
    return answer;
}

int main() {
    cout << solution({"119", "97674223", "1195524421"});
}