#include <bits/stdc++.h>
using namespace std;


    
int main() {
    // 들어오는게 지금 있는거보다 작으면 push 
    // 크면 pop 연산 
    // 첫번째 값이 제일 크면 "NO" 출력 

    int n; // 수열개수 
    cin >> n;
    
    vector<int> nums(n, 0);
    vector<char> output;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    stack<int> st;

    int ja = 1;  // 자연수

    for (int i = 0; i < n; i++) {
        int now = nums[i]; // nums[i];

        if (ja <= now) {
            while (ja <= now) {
                st.push(ja);
                ja++;
                output.push_back('+');
            }
        }

        if (st.empty() || st.top() != now) {
            cout << "NO";
            return 0;
        }

        st.pop();
        output.push_back('-');
    }


    for (auto o : output) {
        cout << o << "\n";
    }
    
}