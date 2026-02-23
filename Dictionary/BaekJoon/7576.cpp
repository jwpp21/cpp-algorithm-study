#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m)); // 박스를 2차원 벡터 행렬로
    queue<pair<int, int>> q; // bfs를 위한 queue

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) q.push({ i,j }); // 노드가 1이면 그 지점부터 탐색 시작이기 때문에 미리 1이면 전부 queue에 넣어두기
        }
    }

    int dr[4] = { -1,1,0,0 };
    int dc[4] = { 0,0,-1,1 };

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0;k < 4;k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue; 
            if (box[nr][nc] != 0) continue; // 0이 아니라면 bfs 진행 x

            box[nr][nc] = box[r][c] + 1; // 조건 전부 충족시 기존의 노드보다 +1값을 더함으로써 시작점과의 거리 표현
            q.push({ nr, nc });

        }
    }
    int max = box[0][0];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (box[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (max < box[i][j]) max = box[i][j];
        }
    }
    cout << max - 1;
    return 0;
}
