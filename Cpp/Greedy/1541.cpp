// 잃어버린 괄호
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter)) {
        result.push_back(splitdata);
    }
    return result;
} 

int sumPlus(string input) {
    vector<string> temp = split(input, '+');
    vector<int> ret;

    int tempSum = 0;

    for (auto s : temp) {
        tempSum += stoi(s);
    }
    return tempSum;
}

int main() {
    string s;
    int answer = 0;
    cin >> s;

    vector<string> partial = split(s, '-');

    for (int i = 0; i < partial.size(); i++) {
        int sum = sumPlus(partial[i]);
        if (i == 0) { // 첫번째 덩어리일 때
            answer += sum;
        } else {
            answer = answer - sum;
        } 
    }
    cout << answer << '\n';
}

/*
int main() {
    string s;
    vector<int> plus;
    int sum = 0;
    
    cin >> s;

    if (s.find("-") != string::npos)  {
        vector<string> str = split(s, '-');    

        // 식 돌면서 + 계산을 마친 상태 
        for (int i = 1; i < str.size(); i++) {
            plus.resize(str.size());
            vector<string> temp; // +가 있으면 split 해서 담을 temp 벡터
            
            if (str[i].find('+')) {
                plus = sumPlus(str[i]);
            }
        }
        for (int p : plus) {
            sum += p;
        }
        cout << stoi(str[0]) - sum << '\n';

    } else {
        plus.resize(split(s, '+').size());
        plus = sumPlus(s);
        for (int p : plus) {
            sum += p;
        }
        cout << sum << '\n';
    }
}*/