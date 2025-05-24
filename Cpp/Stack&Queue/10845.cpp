#include <bits/stdc++.h>
using namespace std;
queue<int> q;

void push(int a);
int pop();
int size();
int empty();
int front();
int back();

int main() {
    int n;
    cin >> n;

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s.find("push") != string::npos) {
            // 명령어가 push이면 
            int a;
            cin >> a;
            push(a);
            
        } else if (s == "front") { cout << front() << '\n'; } 
          else if (s == "back") { cout << back() << '\n'; }
          else if (s == "size") { cout << size() << '\n'; }
          else if (s == "empty") { cout << empty() << '\n'; }
          else if (s == "pop") { cout << pop() << '\n'; }
    }
}

void push(int x) {
    q.push(x);
}

int pop() {
    int x;
    if (!q.empty()) {
        x = q.front();
        q.pop();
    } else {
        x = -1;
    }
    return x;
}

int size() {
    int x = q.size();
    return x;
}

int empty() {
    if (q.empty()) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

int front() {
    int x;
    if (!q.empty()) {
        x = q.front();
    } else {
        x = -1;
    }
    return x;
}

int back() {
    int x;
    if (!q.empty()) {
        x = q.back();
    } else {
        x = -1;
    }
    return x;
}
