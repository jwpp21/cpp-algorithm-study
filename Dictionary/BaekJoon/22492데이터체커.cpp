My Answer
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int x, radius;
    stack<pair <int, int>> st;
    vector<pair<int, int>> v;
    for (int i = 0;i < n;i++) {
        cin >> x >> radius;
        v.push_back(make_pair(x, radius));
    }
    sort(v.begin(), v.end());
    
    st.push(make_pair(v[0].first, v[0].second));    

    for (int i = 1;i < n;i++) {
        while (!st.empty() || !(st.size() == n)) {
            // 외부에 있는경우
            if ((st.top().second + v[i].second) < abs(st.top().first - v[i].first)) {
                st.pop();
            }
            // 내부에 있는경우
            else if (abs(st.top().second - v[i].second) > abs(st.top().first - v[i].first)) {
                break;
            }
            else if (st.top().first - v[i].first == 0)
            {
                st.pop();
                break;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
        st.push(make_pair(v[i].first, v[i].second));
    }
    if (st.size() == 1)
        cout << "YES";

    return 0;
}
