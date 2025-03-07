#include <bits/stdc++.h>
using namespace std;

int main() {
 
    

    while (true) {    
        
        int a; 
        cin >> a;

        if (a == 0) { break; }
        
        string str = to_string(a);
        string rstr = str;

        reverse(rstr.begin(), rstr.end());

        if (str == rstr) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }   
}