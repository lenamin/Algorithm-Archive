#include <bits/stdc++.h>
using namespace std;

// I 16 -> 16을 Insert 
// D 1, D -1 은 각각 최대값 삭제, 최소값 삭제



int main() {
    
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        multiset<int> ms;
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            string s;
            int k;

            cin >> s >> k;

            if (s == "I") {
                ms.insert(k);

            } 
            
            if (s == "D") {
                if (k == 1 && !ms.empty()) {
                    auto tmp = --ms.end();
                    ms.erase(tmp);


                }
                
                if (k == -1 && !ms.empty()) {
                    auto tmp = ms.begin();
                    ms.erase(tmp);

                }
            }
        }

        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            cout << *(--ms.end()) << " " << *ms.begin() << '\n';
        }

        // if (!ms.empty()) ms.clear();
    }

}