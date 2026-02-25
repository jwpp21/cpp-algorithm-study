#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// 전체적인 아이디어
// grid중 가장 높은 높이까지 전체 순회해서 가장 많은 영역이 언젠가를 maxCnt에 저장
// visited배열 assign을 이용해 초기화
// if(visited==true || grid <=h(높이)) 조건문으로 거름
// 한 덩어리 찾을때마다 ++
// 그 덩어릴 maxCnt와 비교후 최종 maxCnt 출력

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int maxHeight = 1;
    int maxCnt = 0;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> grid[i][j];
            maxHeight = max(maxHeight, grid[i][j]);
        }
    }

   
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    for (int k = 0;k < maxHeight;k++) {
        visited.assign(n, vector<bool>(n, false)); // 매 k(높이) 마다 visited벡터 초기화
        int cnt = 0; // 마찬가지로 cnt도 초기화
        queue<pair<int, int>> q;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (visited[i][j] || grid[i][j] <= k) continue;


                cnt++; // 덩어리 발견

                visited[i][j] = true;
                q.push({ i,j });

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dir = 0;dir < 4;dir++) { // 상하좌우 조건 확인
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (visited[nx][ny]) continue;
                        if (grid[nx][ny] <= k) continue; // 높이로 거름

                        visited[nx][ny] = true;
                        q.push({ nx, ny });
                    }
                }
               
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt;
    return 0;
}
