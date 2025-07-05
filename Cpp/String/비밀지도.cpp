#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // 일단 arr1, arr2로 들어오는 배열의 10진수를 2진수로 변환해야하나? 
    // 아니면 10진수를 그냥 비트 연산해도 mysql처럼 그렇게 되나? 일단 한번 해보자 
    // mysql처럼은 안되네. 그럼 일단 2진수로 바꿔서 비트 연산을 해야겠다. 비트연산은 되나? 
    
    // 일단 2진수로 변환하자 
    // 그리고 OR 연산을 하자 
    // 그리고 결과값을 1은 #으로, 0은 ' '으로 벡터에 삽입하자 
    
    
    vector<string> barr1;
    vector<string> barr2;
    vector<string> v;
    
    for (int i = 0; i < n; i++) {
        bitset<16> b1(arr1[i]);
        string b = b1.to_string().substr(16 - n);
        barr1.push_back(b);
        
        bitset<16> b2(arr2[i]);
        string d = b2.to_string().substr(16 - n);
        barr2.push_back(d);
        
        string ss = (b1 | b2).to_string().substr(16 - n);
        v.push_back(ss);
        
    }

    
    for (int i = 0; i < n; i++) {
        string tmp;
        for (char c : v[i]) {
            
            if (c == '1') {
                tmp.push_back('#');
                
            } else if (c == '0') {
                tmp.push_back(' ');
            }
        }
        answer.push_back(tmp);
    }
   
    return answer;
}