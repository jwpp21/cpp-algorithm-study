#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) { // dfs 재귀로 구현
    visited[v] = true;
    cout << v << ' '; // 방문한 노드 하나씩 찍기
    for (int nxt : adj[v]) {
        if (!visited[nxt]) dfs(nxt); // 첫방문이 아니라면 dfs 호출
    }
}

void bfs(int start) { // bfs 구현
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' '; // 방문 노드 출력
        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    adj.assign(N + 1, {}); // 재할당
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end()); // 정렬을 해야 만 작은 숫자 노드 우선 탐색 가능
    }

    visited.assign(N + 1, false); // 재 할당
    dfs(V);
    cout << '\n';

    visited.assign(N + 1, false); // dfs로 이미 탐색한 visited 벡터 초기화(재할당)
    bfs(V);
    cout << '\n';

    return 0;
}
