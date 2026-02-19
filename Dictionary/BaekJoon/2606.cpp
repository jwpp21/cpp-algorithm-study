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
    vector<vector<int>> vec(n + 1); // 그래프 저장 2차원 인접 리스트
    
    for (int i = 0;i < m;i++) { // 노드 연결
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false); // 방문 벡터
    int cnt = 0;

    queue<int> q;
    q.push(1); // 무조건 1번 노드에서 시작
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : vec[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = true; // 첫 방문일 경우 (감염 당한 경우)
            q.push(nxt);
            cnt++; // 감염수 증가
        }
    }
    cout << cnt << "\n";
    return 0;
}
