#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    
#include <queue>
using namespace std;

// BFS의 기본형
// 1. 정수 값의 범위 0 ~ 100000 2. 움직임에 대한 같은 가중치 >>> BFS 선택
// 처음 설계에 Greedy를 선택했지만 위의 이유로 BFS 선택

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;                 // n: 시작 위치, m: 목표 위치
    cin >> n >> m;

    const int MAX = 100000;   // 문제에서 허용하는 위치 범위(0 ~ 100000)
    vector<int> dist(MAX + 1, -1);
    // dist[x] = 시작점 n에서 x까지의 최단 이동 횟수
    // -1이면 아직 방문(도달)하지 않은 상태

    queue<int> q;             // BFS에 쓰는 큐(먼저 들어간 상태부터 처리)

    dist[n] = 0;              // 시작점까지의 거리는 0
    q.push(n);                // 시작점부터 탐색 시작

    while (!q.empty()) {      // 큐가 빌 때까지(더 확장할 상태가 없을 때까지)
        int x = q.front();    // 현재 위치
        q.pop();

        // BFS 특성: 어떤 정점(위치)을 '처음' 꺼냈을 때 dist[x]는 최단 거리로 확정
        if (x == m) {         // 목표에 도달하면 그게 최소 이동 횟수
            cout << dist[x] << "\n";
            return 0;
        }

        // 현재 위치 x에서 한 번 이동으로 갈 수 있는 다음 위치 3개
        int nexts[3] = { x - 1, x + 1, x * 2 };

        for (int i = 0; i < 3; i++) {
            int y = nexts[i];          // 다음 위치 후보

            // 범위 밖이면 버림 (배열 접근 방지)
            if (y < 0 || y > MAX) continue;

            // 이미 방문했으면 스킵:
            // BFS에서는 처음 방문했을 때가 최단 거리이므로, 다시 볼 필요 없음
            if (dist[y] != -1) continue;

            // 아직 방문 안 했으면, 현재 거리 + 1이 y의 최단 거리
            dist[y] = dist[x] + 1;

            // y를 큐에 넣어 다음 레벨(거리+1)에서 확장
            q.push(y);
        }
    }

    return 0; // 이 문제에서는 보통 여기까지 안 옴(항상 도달 가능)
}
