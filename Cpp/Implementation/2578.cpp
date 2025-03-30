#include <bits/stdc++.h>
using namespace std;

int bingo[26][26];
int r[6];
int c[6];
int s[2];
int rcnt;
int tcnt;
bool visited[25][25] = {false};

int main() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }

    while (true) {
        int n;
        cin >> n;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                if (bingo[i][j] == n && !visited[i][j]) {
                    visited[i][j] = true;
                    rcnt++;

                    r[i]++;
                    if (r[i] == 5) { 
                        tcnt++; 
                        if (tcnt == 3) {
                            cout << rcnt << '\n';
                            return 0;
                        }
                    }
                    
                    c[j]++;
                    if (c[j] == 5) { 
                        tcnt++;
                        if (tcnt == 3) {
                            cout << rcnt << '\n';
                            return 0;
                        }
                    }    
                    
                    if (i == j) {
                        s[0]++;
                        if (s[0] == 5) { 
                            tcnt++;
                            if (tcnt == 3) {
                                cout << rcnt << '\n';
                                return 0;
                            }
                        }
                    } 
                    if (i + j == 4) {
                        s[1]++;
                        if (s[1] == 5) {
                            tcnt++;
                            if (tcnt == 3) {
                                cout << rcnt << '\n';
                                return 0;
                            }
                        }
                    }
                }
            }   
        }
    }
    return 0;
}