#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> set1;
set<string> set2;
vector<string> result;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set1.insert(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        set2.insert(s);
    }

    // 교집합을 찾아야 하는데,,,,
    // 어떻게 찾으면 좋을까? 

    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(result));
    sort(result.begin(), result.end());

    cout << result.size() << '\n';

    for (auto r : result) {
        cout << r << '\n';
    }    

}