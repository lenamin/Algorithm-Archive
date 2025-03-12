#include <bits/stdc++.h>
using namespace std;

char arr[27][2];
void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char pa, left, right;
        cin >> pa >> left >> right;
        
        int node = pa - 'A';

        if (left == '.') {
            arr[node][0] = -1;
        } else {
            arr[node][0] = left - 'A';
        }

        if (right == '.') {
            arr[node][1] = -1;
        } else {
            arr[node][1] = right - 'A';
        }
    }

    preOrder(0);
    cout << '\n';
    inOrder(0);
    cout << '\n';
    postOrder(0);
    cout << '\n';
    
}

void preOrder(int now) {
    if (now == -1) {
        return;
    } 

    cout << (char)(now + 'A');
    preOrder(arr[now][0]);
    preOrder(arr[now][1]);
}

void inOrder(int now) {
    if (now == -1) {
        return;
    }

    inOrder(arr[now][0]);
    cout << (char)(now + 'A');
    inOrder(arr[now][1]);
}

void postOrder(int now) {
    if (now == -1) {
        return;
    }

    postOrder(arr[now][0]);
    postOrder(arr[now][1]);
    cout << (char)(now + 'A');
}