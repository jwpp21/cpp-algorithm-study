#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() { // 3차원 그래프
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, h;
    cin >> m >> n >> h; // x >> y >> z 순으로 입력받음

    vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m))); // 3차원을 벡터로 표현할땐 높이>세로>가로 순
    queue<tuple<int, int ,int>> q; // queue를 3차원으로 이용하기 위해서 tuple이용

    for (int i = 0;i < h;i++) {
        for (int j = 0;j < m;j++) {
            for (int k = 0;k < n;k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) q.push({ i,j,k });
            }
            
        }
    }

    int dz[6] = { 1,-1, 0, 0, 0, 0 }; // 3차원이니 그에 맞춰서 요소 위 아래 상 하 좌 우로 나눔
    int dy[6] = { 0, 0, 1,-1, 0, 0 };
    int dx[6] = { 0, 0, 0, 0, 1,-1 };

    while (!q.empty()) {
        auto [x, y,z] = q.front();
        q.pop();

        for (int k = 0;k < 6;k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz <0 || nz >=h) continue;
            if (box[nx][ny][nz] != 0) continue;

            box[nx][ny][nz] = box[x][y][z] + 1;
            q.push({ nx,ny,nz });

        }
    }
    int max = 1; // 1로 설정
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            for (int k = 0;k < h;k++) {
                if (box[i][j][k] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                
                if (max < box[i][j][k]) max = box[i][j][k];
            }
        }
    }
    if (max == 1) cout << 0 << endl;
    else
        cout << max - 1; // 1로 설정함으로써 이미 전부 다 익어있다고 하더라도 1-1 == 0으로 만들 수 있다.
    return 0;
}
