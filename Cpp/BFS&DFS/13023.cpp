#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 친구관계 adjList로 받기 => vector<list<int>> 타입이 되겠지 
// 각 노드에서 (vertex에서) dfs 를 수행한다 => dfs 호출할 때마다 depth 값을 1씩 증가해서 A -> B -> C -> D -> E 모두가 연결되어 친구인지 확인 
// 5인 경우를 찾으면 1 반환하고 종료 

  // dfs 함수 : 
    // depth가 5이거나 끝나게 되면 함수 종료 
    // 지금 반환한 노드 값을 visited 배열에 저장 
    // 현재 노드에 연결된 연결리스트를 쭉 돌면서 아직 방문하지 않은 노드에 대해서 dfs 수행 (여기서 depth값 핸들링하면되겠지) 
    // visited 배열에서 현재 방문한 노드는 삭제 ...? 하면 되나? // 이거 해보고 디버깅 해보기 


static int vertex, edge;
static bool isArrived = false;

static vector<bool> visited;
static vector<list<int>> relationships;
void dfs(int currentVertex, int depth);    

void dfs(int currentVertex, int depth) {
    cout << "depth: " << depth << endl;
    if (depth == 5 || isArrived == true) {
        isArrived = true;
        return;
    }
    
    visited[currentVertex] = true; // 방문처리 
    
    for (auto i : relationships[currentVertex]) {
        if (!visited[i]) {
            dfs(i, depth + 1);
            
        }
    }
    visited[currentVertex] = false; // 백 트래킹 ! 
}

int main()
{
    cin >> vertex >> edge;
    
    // visited 배열 초기화, 아직 모두 방문안했으니까 false로 
    visited = vector<bool>(vertex + 1, false);
    // 연결리스트 사이즈 설정
    relationships.resize(vertex + 1);

    for (int i = 0; i < edge; i++) {
        int s, e;
        cin >> s >> e;
        relationships[s].push_back(e);
        relationships[e].push_back(s);
    }

    for (int i = 0; i < vertex; i++) {
        dfs(i, 1);
    }

    if (isArrived) {
        cout << 1;
    } else {
        cout << 0;
    }

}