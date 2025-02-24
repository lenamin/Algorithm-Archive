// 3월 1주차 큐2 

/*
#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
    unordered_map<string, int> mp = {
        {"push", 1}, {"pop", 2}, {"front", 3}, {"back", 4}, {"size", 5}, {"empty", 6}
    };
    // switch로 명령을 관리하고 싶었으나, 오히려 unordered_map 사용하면 해시충돌의 위험이 있다고 함 
    // 시간초과 떴음,,, 
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string comm;
        cin >> comm;
        
        int x = 0;
        
        switch (mp[comm]) {
            case 1:  // push인 경우         
                cin >> x;
                q.push(x);
                cout << x << '\n';
            break;

            case 2: // pop인 경우 
                if (!q.empty()) {
                    x = q.front();
                    cout << x << '\n';
                    q.pop();
                } else {
                    cout << -1 << '\n';
                }
            break;

            case 3: // front
                if (!q.empty()) {
                    x = q.front();
                    cout << x << '\n';
                } else {
                    cout << -1 << '\n';
                }
            break;
            
            case 4: // back
                if (!q.empty()) {
                    x = q.back();
                    cout << x << '\n';
                } else {
                    cout << -1 << '\n';
                }
            break;

            case 5: // size
                x = q.size();
                cout << x << '\n';
            break;
            
            case 6: // empty
                if (q.empty()) x = 1; 
                else x = 0;
                // x = q.empty() ? 1 : 0;
                cout << x << '\n';
            break;
        
            default:
                break;
            }
            
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    ostringstream out; // 출력을 한 번에 모아서 처리

    for (int i = 0; i < n; i++) {
        string comm;
        cin >> comm;
        
        if (comm == "push") {
            int x;
            cin >> x;
            q.push(x);
        } 
        else if (comm == "pop") {
            if (!q.empty()) {
                out << q.front() << '\n';
                q.pop();
            } else {
                out << "-1\n";
            }
        } 
        else if (comm == "front") {
            if (!q.empty()) out << q.front() << '\n';
            else out << "-1\n";
        } 
        else if (comm == "back") {
            if (!q.empty()) out << q.back() << '\n';
            else out << "-1\n";
        } 
        else if (comm == "size") {
            out << q.size() << '\n';
        } 
        else if (comm == "empty") {
            out << (q.empty() ? "1\n" : "0\n");
        }
    }

    cout << out.str(); // 모아둔 출력 한 번에 처리
}
