#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E; // 정점, 간선 갯수
    cin >> V >> E;
    int start; // 시작 정점
    cin >> start;

    vector<vector<pair<int, int>>> vec(V + 1); // (to, weight) // 정점 , {도착 정점, 가중치}
    for (int i = 0;i < E;i++) {
        int u, v, w; // 시작 정점 , 목표 정점, 가중치
        cin >> u >> v >> w;
        vec[u].push_back({ v,w });
    }
    const int INF = 1e9;

    vector<int> dist(V + 1, INF); // 각 정점까지의 거리 무한대로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선순위큐를 최소힙으로 변환

    dist[start] = 0; // 시작점 기준이므로 dist[start] = 0 으로 설정
    pq.push({ 0, start }); // 현재 dist[cur], cur. 즉 현재까지의 거리, 현재 정점 push

    while (!pq.empty()) {
        auto [d, u] = pq.top(); // 현재 거리와(dist[cur], 정점 pop();
        pq.pop();

        if (d != dist[u]) continue; // 만약

        for (auto [to, w] : vec[u]) { // 정점 u로 시작되는 정점 순회
            if (dist[to] > d + w) { // 가중치 + 현재 거리 더한값과 비교
                dist[to] = d + w;
                pq.push({ dist[to], to }); // 값이 바뀌었다면 방문한 것이므로 pq에 push 

            }
        }
            
    }
    for (int i = 1;i <= V;i++) {
        if (dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
   }

    

    return 0;
}
