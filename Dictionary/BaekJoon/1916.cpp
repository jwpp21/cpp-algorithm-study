#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> vec(V + 1); // (to, weight)
    for (int i = 0;i < E;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({ v,w });
    }
    const int INF = 1e9;

    vector<int> dist(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start, goal;
    cin >> start >> goal;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [to, w] : vec[u]) {
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({ dist[to], to });

            }
        }
            
    }    
    cout << dist[goal];
    return 0;
}
