#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 2차원 grid and 한 덩어리 찾기 문제

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int M, N, K; // M이 가로, N이  세로
        cin >> M >> N >> K;
        vector<vector<int>> grid(N, vector<int>(M, 0)); // 2차원 그리드 0으로 초기화
        vector<vector<bool>> visited(N, vector<bool>(M, false)); // visited도 마찬가지로 초기화

        for (int i = 0; i < K; i++) {
            int x, y; // x가 열(가로), y가 행(세로)
            cin >> x >> y;  
            grid[y][x] = 1; // grid[y][x] 주의
        }

        int dr[4] = { -1, 1, 0, 0 }; 
        int dc[4] = { 0, 0, -1, 1 };
        
        int cnt = 0;

        for (int r = 0;r < N;r++) {
            for (int c = 0;c < M;c++) {
                if (grid[r][c] == 0 || visited[r][c]) continue; // 벽이면 == 배추가 심어져 있지 않은 곳 or 이미 방문한 곳(덩어리 계산 끝난 곳)

                cnt++; // 덩어리 최초발견 경우
                queue<pair<int, int>> q;
                visited[r][c] = true;
                q.push({ r, c });

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    for (int k = 0;k < 4;k++) {
                        // 상하좌우 인접 노드 확인
                        int nr = r + dr[k]; 
                        int nc = c + dc[k];

                      
                        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue; // 벗어날 경우 컷
                        if (visited[nr][nc]) continue;  // 이미 방문 노드인경우 컷
                        if (grid[nr][nc] == 0) continue; // 벽인 경우 == 배추가 심어져 있지 않은 경우 컷

                        visited[nr][nc] = true;
                        q.push({ nr, nc });
                    }
                }
            }
        }
       
        cout << cnt << "\n";
    }
    
    return 0;
}
