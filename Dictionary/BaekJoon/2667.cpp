#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
// 2차원 그리드 bfs문제
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n); // 빈칸없는 입력 >>> string 벡터 사용
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(n, 0)); // 2차원 그리드 방문배열 초기화
    vector<int> houses; // 결과 벡터


    int dr[4] = { -1, 1, 0,0 };
    int dc[4] = { 0, 0,-1,1 };

    for (int i = 0;i < n;i++) { // 모든 노드를 순환하면서 한 덩어리 발견할때마다 멈춤
        for (int j = 0;j < n;j++) {
            if (grid[i][j] == '0' || visited[i][j]) continue;

            int house = 0;
            visited[i][j] = true;
            queue<pair<int, int>> q;
            q.push({ i, j }); // 덩어리 찾으면 bfs 작동

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                house++; // 한 덩어리 안에 있는 노드 개수
                for (int k = 0;k < 4;k++) { // 상하좌우 인접노드 접근
                    int nr = r + dc[k];
                    int nc = c + dr[k];

                    if (nr < 0 || nr >= n || nc >= n || nc < 0) continue;
                    if (grid[nr][nc] == '0') continue;
                    if (visited[nr][nc]) continue;

                    visited[nr][nc] = true; // 조건에 걸리는게 없다면 새로운 노드기에 방문처리
                    q.push({ nr, nc }); // bfs 진행
                }
            }
            houses.push_back(house); // 벡터에 삽입
        }
    }

    sort(houses.begin(), houses.end());
    cout << houses.size() << endl;
    for (int x : houses) cout << x << "\n";

    return 0;
}
