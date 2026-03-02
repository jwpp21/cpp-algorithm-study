#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;
// 0-1 BFS
// 전체적인 아이디어
// 0-1 BFS를 활용 cost == 0 >> push_front || cost == 1 >> push_back
// deque활용
// dist를 visited처럼 활용 + 최소거리 저장
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    vector<vector<int>> dist(N, vector<int>(M, INF));
    deque<pair<int, int>> dq;

    dist[0][0] = 0;
    dq.push_front({ 0, 0 });

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    while (!dq.empty()) {
        auto [r, c] = dq.front();
        dq.pop_front();
      

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;  

            int cost = (grid[nr][nc] == '1') ? 1 : 0;

            if (dist[nr][nc] > dist[r][c] + cost) {
                dist[nr][nc] = dist[r][c] + cost;
                if (cost == 0) dq.push_front({ nr, nc });
                else dq.push_back({ nr, nc });
            }
        }
    }

    cout << dist[N - 1][M - 1] << "\n";
    return 0;
}
