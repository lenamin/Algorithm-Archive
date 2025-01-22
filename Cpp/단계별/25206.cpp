#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, g;
    double c;
    double sum = 0.0;
    double creditSum = 0.0;
    vector<double> ans;

    for (int i = 0; i < 20; i++) {
        cin >> s >> c >> g;
        
        if (g == "P") continue;

        creditSum += c;
        
        if (g == "F") ans.push_back(0.0);
        else if (g == "A+") ans.push_back(4.5 * c);
        else if (g == "A0") ans.push_back(4.0 * c);
        else if (g == "B+") ans.push_back(3.5 * c);
        else if (g == "B0") ans.push_back(3.0 * c);
        else if (g == "C+") ans.push_back(2.5 * c);
        else if (g == "C0") ans.push_back(2.0 * c);
        else if (g == "D+") ans.push_back(1.5 * c);
        else if (g == "D0") ans.push_back(1.0 * c);
    }

    for (double a : ans) {
        sum += a;
    }
    cout << sum / creditSum << '\n';
}