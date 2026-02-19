#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n + 1); // 인접리스트 
    
    for (int i = 0;i < m;i++) { // 노드 연결 과정
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false); // 방문 배열
    int cnt = 0;

    for (int i = 1;i <= n;i++) {
        if (visited[i]) continue;

        cnt++; // 새 덩어리를 찾았을 경우 왜? bfs로 다 돌았는데 첨보는 노드니까
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : vec[cur]) {
                if (visited[nxt]) continue;
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
