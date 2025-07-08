#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    vector<string> cities2(cities.size());
    
    for (int i = 0; i < cities.size(); i++) {
        string s;
        for (char c : cities[i]) {
            s += tolower(c);
        }
        cities2[i] = s;
    }
    
    for (int i = 0; i < cities2.size(); i++) {
        string city = cities2[i];
        
        auto it = find(cache.begin(), cache.end(), city);
        
        if (cacheSize == 0) {
            return 5 * cities2.size();
        } else {
             if (it == cache.end())  {
                answer += 5;
                if (cache.size() < cacheSize) {
                    cache.push_back(city);    
                } else if (!cache.empty() & (cache.size() >= cacheSize)) {
                    cache.pop_front();
                    cache.push_back(city);
                }
            } else {                
                cache.erase(it);
                cache.push_back(city);
                answer += 1;
             }
        }
    }
    return answer;
}