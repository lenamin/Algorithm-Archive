#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const vector<int> dx { 0, 1, 0, -1 };
const vector<int> dy { 1, 0, -1, 0 };

static vector<vector<int>> numbers;
static vector<vector<bool>> visited;

void bfs(int n, int m) {
  queue<pair<int, int>> q;
  q.push({n, m});
  cout << "큐에 추가: (" << n << ", " << m << ")" << endl;
  visited[n][m] = true;

  while (!q.empty()) {
    int currentX = q.front().first;
    int currentY = q.front().second;
    cout << numbers[currentX][currentY] << endl;
    q.pop();
    
    for (int k = 0; k < 4; k++) {
      // 상하좌우 이동해보는거지 
      int x = currentX + dx[k];
      int y = currentY + dy[k];

      // 이 중에 모두 이동할 수 있는 건 아니니까 검사해야지 
      if (x >= 0 && y >= 0 && x < numbers.size() && y < numbers[0].size()) {
        if (numbers[x][y] == 1 && !visited[x][y]) {
          cout << "x: " << x << "y: " << y << endl;
          visited[x][y] = true;
          numbers[x][y] = numbers[currentX][currentY] + 1;
          q.push({x, y});
        }
      }
    }
  }
}

int main()
{

  int n, m;
  cin >> n >> m;

  numbers.resize(n, vector<int>(m));
  visited.resize(n, vector<bool>(m, false));
  
  // 1. 상하좌우 네 방향을 보며 인접한 칸을 본다. 
  // 2. 인접한 칸의 숫자가 1이면서 visited가 false 이면 큐 삽입한다 
  // 3. (n, m)에 도달할 때 까지 bfs 호출 반복 
  // 4. 처음 도달했을 때 depth 출력 

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j < m; j++) {
      numbers[i][j] = temp[j] - '0';
    }
  }
  bfs(0, 0);
  cout << numbers[n-1][m-1] << '\n';
} 

