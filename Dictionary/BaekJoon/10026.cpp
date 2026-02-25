#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
// 전체적인 방향성은 이러하다
// grid를 색약 / 비색약으로 나눠서 직관적으로 두번 돌리는 것
// 그를 위해 countRegion이라는 함수를 만들어 사용한다

int n;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<bool>> visited;

int countRegions(vector<string>& grid) {
    visited.assign(n, vector<bool>(n, false));
    int cnt = 0;
    
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (visited[i][j]) continue;

            cnt++; // 한 덩어리 찾을 때 마다 ++
            char color = grid[i][j]; // 색깔 저장

            queue<pair<int, int>> q;
            visited[i][j] = true;
            q.push({ i,  j });


            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0;k < 4;k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    if (grid[nx][ny] != color) continue; // 색깔다르면 멈춤

                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }   
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<string> RGB(n);
    for (int i = 0;i < n;i++) {
        cin >> RGB[i];
    }
    
    int normal = countRegions(RGB);

    vector<string> rrb = RGB;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (rrb[i][j] == 'R') rrb[i][j] = 'G'; // 색약은 R과 G가 구분안되므로 통합
        }
    }
   
    int blind = countRegions(rrb);

    cout << normal << " " << blind;
    return 0;
}
