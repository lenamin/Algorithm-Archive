#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> a(10, vector<bool>(10, 0));
vector<bool> visited(10, 0);

void go(int from) {
  // 방문처리 
  visited[from] = 1;

  for (int i = 0; i < 10; i++) {
    if (visited[i]) continue;
    if (a[from][i]) {
      go(i);
    }
  }

}

int main() {
  

  a[1][2] = 1;
  a[1][3] = 1;
  a[3][4] = 1;

  a[2][1] = 1;
  a[3][1] = 1;
  a[4][3] = 1;

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      if (a[i][j] && visited[i] == 0) {
        go(i);
      }
    }
    
  }
}