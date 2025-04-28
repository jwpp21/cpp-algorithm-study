#include <iostream>
#include <queue>
#include <map>
using namespace std;

void clean(priority_queue<int>& pq, map<int, int>& deleted) {
    while (!pq.empty() && deleted[pq.top()] > 0) {
        deleted[pq.top()]--;
        pq.pop();
    }
}

void clean_min(priority_queue<int, vector<int>, greater<int>>& pq, map<int, int>& deleted) {
    while (!pq.empty() && deleted[pq.top()] > 0) {
        deleted[pq.top()]--;
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        priority_queue<int> maxHeap; 
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        map<int, int> deleted;

        for (int i = 0; i < k; ++i) {
            char cmd;
            int x;
            cin >> cmd >> x;

            if (cmd == 'I') {
                maxHeap.push(x);
                minHeap.push(x);
            }
            else if (cmd == 'D') {
                if (x == 1) {
                    clean(maxHeap, deleted);
                    if (!maxHeap.empty()) {
                        deleted[maxHeap.top()]++;
                        maxHeap.pop();
                    }
                }
                else if (x == -1) { 
                    clean_min(minHeap, deleted);
                    if (!minHeap.empty()) {
                        deleted[minHeap.top()]++;
                        minHeap.pop(); 
                    }
                }
            }
        }

        clean(maxHeap, deleted);
        clean_min(minHeap, deleted);

        if (maxHeap.empty() || minHeap.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << maxHeap.top() << " " << minHeap.top() << "\n";
        }
    }

    return 0;
}
// map 이용한 풀이
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        map<int, int> mp;
        int n; cin >> n;
        for (int i = 0;i < n;i++) {
            char cmd; cin >> cmd;
            int x;cin >> x;

            if (cmd == 'I') {
                mp[x] += 1;
            }
            else {
                if (mp.empty()) continue;
                if (x == -1) {
                    if (mp.begin()->second == 1) {
                        mp.erase(mp.begin()->first);
                    }
                    else {
                        mp.begin()->second--;
                    }
                }
                else {
                    if (mp.rbegin()->second == 1) {
                        mp.erase(mp.rbegin()->first);
                    }
                    else {
                        mp.rbegin()->second--;
                    }
                }
            }
        }
        if (mp.empty()) cout << "EMPTY\n";
        else cout << mp.rbegin()->first << ' ' << mp.begin()->first << '\n';
    }

    return 0;
}


// 예제 하나 더

