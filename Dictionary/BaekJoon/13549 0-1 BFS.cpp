#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <queue>
using namespace std;
// 0-1 BFS 문제
// 전체적인 아이디어
// 1. deque 활용해서 가중치 0 >> push_front, 가중치 1 >> push_back
// 2. dist를 단순 visited로 활용하는게 아닌 계속해서 최소값으로 수정


const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    const int MAX = 100000;
    vector<int> dist(MAX + 1, INF);

    deque<int> dq;

    dist[N] = 0;
    dq.push_front(N);

    while (!dq.empty()) {
        int x = dq.front();
        dq.pop_front();

        if (x == K) {
            cout << dist[x] << "\n";
            return 0;
        }
        int nxt[3] = { x - 1, x + 1, 2 * x };

        for (int k = 0;k < 3;k++) {
            int y = nxt[k];
 
            if (y <0 || y>MAX) continue;
            
            if (k < 2) {
                if (dist[y] > dist[x]+1) {
                    dist[y] = dist[x] + 1;
                    dq.push_back(y);
                }
            }
            else {
                if (dist[y] > dist[x]) {
                    dist[y] = dist[x];
                    dq.push_front(y);
                }
            }
        }
        
    }
    cout << dist[K];
    return 0;
}
