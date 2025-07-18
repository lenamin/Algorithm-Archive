#include <bits/stdc++.h>
using namespace std;


vector<string> split(string s, char delimeter) {
    vector<string> result;
    stringstream ss(s);
    string token;

    while (getline(ss, token, delimeter)) {
        result.push_back(token);
    }
    return result;
}

int main() {
    string s = "Hello, I'm Hyemin";

    vector<string> result = split(s, ' ');

    for (string s : result) {
        cout << s << '\n';
    }

}