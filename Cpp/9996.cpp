#include <bits/stdc++.h>
using namespace std;

int n;

vector<string> split(const string& input, string delimeter) {
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimeter);

  while (end != string::npos) {
    result.push_back(input.substr(start, end - start));
    start = end + delimeter.size();
    end = input.find(delimeter, start);
  }
  result.push_back(input.substr(start));
  return result;
}

int main() {
  cin >> n;
  string pt;
  vector<string> fn;

  cin >> pt;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    fn.push_back(temp);
  }
  vector<string> splits = split(pt, "*");

  for (auto f : fn) {

    if (splits[0].size() + splits[1].size() > f.size()) { 
      cout << "NE" << '\n';
    } else if (f.find(splits[0]) == 0 && f.rfind(splits[1]) == (f.size() - splits[1].size())) {
      cout << "DA" << '\n';
    } else {
      cout << "NE" << '\n';
    }
  }
}

