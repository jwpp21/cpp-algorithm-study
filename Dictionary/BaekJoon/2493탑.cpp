My Answer
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int weightValue = 1;
    vector <int> res(n);
    vector<int> v;
    while (n--) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    bool isChange = false;

    res[0] = 0;
    for (int i = 1;i < v.size();i++) {
        if (v[i] <= v[i - weightValue]) {
            res[i] = i-weightValue+1;
            isChange = true;
        }
        else {
            while (i - weightValue >= 0) {
                if (v[i] <= v[i - weightValue]) {
                    res[i] = i - weightValue + 1;
                    isChange = true;
                }
                weightValue++;
            }
        }
        if (!isChange)
            res[i] = 0;
        isChange = false;
        weightValue = 1;
    }
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}
