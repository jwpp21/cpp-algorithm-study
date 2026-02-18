#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

// 최단거리 구하는 문제 + 가중치 같음 >> BFS
// 상하좌우 인접한 노드로 이동
// BFS 문제 풀때 고려해야 할 사항
// 1. dist 방문 배열 크기 설정 and 초기화
// 2. 인접노드로 진행할 경우의 수 배열 while문 안에 설정
// 3. 문제에서 주어진 범위 체크, 방문했는지 체크

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;  

    vector<string> maze(n); // 미로가 빈칸없이 주어지기에 string 벡터로 받음
    for (int i = 0; i < n; i++) cin >> maze[i];

    vector<vector<int>> dist(n, vector<int>(m, -1)); // 2차원 벡터 -1로 초기화
    queue<pair<int, int>> q;

    dist[0][0] = 1; // 실제 문제에선 0,0을 >> 1,1로 가정
    q.push({0, 0}); // pair<0, 0>로 push

    // 4방향 벡터(상하좌우)
    int dr[4] = { -1, 1, 0, 0 }; 
    int dc[4] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        if (r == n - 1 && c == m - 1) {
            cout << dist[r][c] << "\n";
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue; // 미로 벗어나는 경우 처리
            if (maze[nr][nc] == '0') continue;                    // 미로의 벽을 만나는 경우 처리
            if (dist[nr][nc] != -1) continue;                     // 이미 방문한 경우 처리

            dist[nr][nc] = dist[r][c] + 1;                        // 이동거리 계산 (BFS여서 무조건 최단거리)
            q.push({ nr, nc });
        }
    }
}
