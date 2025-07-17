#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(s);
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> totals;
    map<string, string> times;
    map<string, int> entries;
    vector<int> answer;
    
    int dt = fees[0]; // 기본 시간 (분)
    int df = fees[1]; // 기본 요금 
    int ut = fees[2]; // 단위 시간 
    int uf = fees[3]; // 단위 요금 

    // mp의 키 : 차량번호 
    // mp[키] = {IN 시간, OUT 시간}
    for (int i = 0; i < records.size(); i++) {
        vector<string> infos = split(records[i], ' ');
        
        string time = infos[0];
        string io = infos[2];
        string carno = infos[1];
        
        vector<string> hms = split(time, ':');
        int t = stoi(hms[0]) * 60 + stoi(hms[1]);
        
        if (io == "IN") {
            entries[carno] = t;
            
        } else if (io == "OUT") {
            totals[carno] += (t - entries[carno]);
            entries.erase(carno);
        }
        
    }
    
    for (auto m : entries) {
        
        totals[m.first] += (1439 - m.second);
        
    }
    
//     int dt = fees[0]; // 기본 시간 (분)
//     int df = fees[1]; // 기본 요금 
//     int ut = fees[2]; // 단위 시간 
//     int uf = fees[3]; // 단위 요금 
    
    for (auto t : totals) {
        cout << t.first << " " << t.second << '\n';      
        
        int time = t.second;
        
        int totalf = df;
        
        if (time > dt) {
            totalf += ((time - dt + ut - 1) / ut) * uf;
        }
        
        answer.push_back(totalf);
        
    }
    
    
    
    return answer;
}

int main() {
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {
        "05:34 5961 IN",
        "06:00 0000 IN",
        "06:34 0000 OUT",
        "07:59 5961 OUT",
        "07:59 0148 IN",
        "18:59 0000 IN",
        "19:09 0148 OUT",
        "22:59 5961 IN",
        "23:00 5961 OUT"
    };
    
    vector<int> result = solution(fees, records);
    
    for (int fee : result) {
        cout << fee << endl;
    }
    
    return 0;
}