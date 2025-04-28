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


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n;
    cin >> n;
    vector<pair<int, int>> circles(n);

    while (n--)
    {
        int x, r;
        cin >> x >> r;

        circles[n] = make_pair(x - r, x + r);
    }

    sort(circles.begin(), circles.end(), [](pair<int, int> left, pair<int, int> right) {
        return left.first != right.first ? left.first < right.first : left.second < right.second;
        });

    bool is_valid = true;
    vector<int> end_stack;

    for (auto circle : circles)
    {
        while (!end_stack.empty() && end_stack.back() < circle.first)
        {
            end_stack.pop_back();
        }

        if (!end_stack.empty() && circle.first <= end_stack.back() && end_stack.back() <= circle.second)
        {
            is_valid = false;
            break;
        }

        end_stack.push_back(circle.second);
    }

    if (is_valid) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
