#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 전체적인 아이디어
// 파티 장소까지 왔다가 다시 자기 집으로 최소거리로 돌아가야 함.
// 근데 단일방향 그래프 이므로
// 정방향, 역방향 그래프 그리드를 두개 만들어서 다익스트라 2번 돌리기

const long long INF = (long long)4e18;

vector<long long> dijkstra(int start, const vector<vector<pair<int, int>>>& adj) { // 다익스트라 함수
    int n = (int)adj.size() - 1;
    vector<long long> dist(n + 1, INF);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [to, w] : adj[u]) {
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({ dist[to], to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, X;
    cin >> V >> E >> X;

    vector<vector<pair<int, int>>> vec(V + 1), rev(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({ v, w });   
        rev[v].push_back({ u, w });   
    }

    auto go = dijkstra(X, vec);
    auto back = dijkstra(X, rev);

    long long ans = 0;
    for (int i = 1; i <= V; i++) {
        if (go[i] >= INF / 2 || back[i] >= INF / 2) continue; // 터질꺼 방비
        ans = max(ans, go[i] + back[i]);
    }

    cout << ans << "\n";
    return 0;
}
