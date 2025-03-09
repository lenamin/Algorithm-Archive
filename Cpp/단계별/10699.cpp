#include <bits/stdc++.h>
using namespace std;

int main() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    

    cout << buf << '\n';
}