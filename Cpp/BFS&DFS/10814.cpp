#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int, string> p;

/*
int main() {
    cin >> n;
    priority_queue<p, vector<p>, greater<>> q;

    for (int i = 0; i < n; i++) {
        int age;
        string name;

        cin >> age >> name;
        
        q.push({age, name});
    }

    while (!q.empty()) {
        p list = q.top();
        cout << list.first << " " << list.second << '\n';
        q.pop();
    }
} */

int main() {
    vector<p> arr;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;

        arr.push_back({age, name});
    }

    stable_sort(arr.begin(), arr.end(), [](const p& a, const p& b) {
        return a.first < b.first;
    });

    for (auto a : arr) {
        cout << a.first << " " << a.second << '\n';
    }
}