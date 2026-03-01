#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 전체 아이디어
// 꼭 지나야 하는 정점이 1에서 v1, v2를 거쳐 V에 도달하는것이기에
// 경우의 수가 1 -> v1 -> v2 -> V or 1-> v2 -> v1 -> V로 나뉜다.
// 고로 두가지 경우의 값을 비교

const long long INF = (long long)4e18;

vector<long long> dijkstra(int start, const vector<vector<pair<int,int>>>& adj) { // 총 3번의 다익스트라를 돌려야하므로 함수 작성
    int n = (int)adj.size() - 1;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq; // 최소 힙

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (auto [to, w] : adj[u]) {
            long long nd = d + (long long)w;
            if (dist[to] > nd) {
                dist[to] = nd;
                pq.push({nd, to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int,int>>> adj(N + 1);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    auto d1  = dijkstra(1, adj); // d1벡터에 1번 노드에서 부터의 모든 정점 거리 저장
    auto dv1 = dijkstra(v1, adj); // dv1 벡터에 v1 노드에서 부터의 모든 정점 거리 저장
    auto dv2 = dijkstra(v2, adj); // dv2 벡터에 v2 노드에서 부터의 모든 정점 거리 저장

    // 1 -> v1 -> v2 -> N      // 첫번째 경우
    long long pathA = INF;      // 만약 d1[v1] + dv1[v2] + dv2[N]; 이 값이 전부 INF 이면 int 자료형으론 터짐 그래서 long long 사용
    if (d1[v1] < INF && dv1[v2] < INF && dv2[N] < INF) // 한 거리라도 INF 라면 도달하지 못했다는 뜻이므로 굳이 계산할 필요 없음
        pathA = d1[v1] + dv1[v2] + dv2[N];

    // 1 -> v2 -> v1 -> N
    long long pathB = INF;
    if (d1[v2] < INF && dv2[v1] < INF && dv1[N] < INF)
        pathB = d1[v2] + dv2[v1] + dv1[N];

    long long ans = min(pathA, pathB);

    if (ans >= INF) cout << -1 << "\n"; // 만약 조건문대로 라면 path A, B 둘다 v1, v2를 지나고 마지막 정점에 도달하는 경우가 없기 때문에 -1 출력
    else cout << ans << "\n";

    return 0;
}
