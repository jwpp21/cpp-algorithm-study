
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	int h,w,n;
	int floor, room;
	cin >> t;
	for (int i = 1;i <=t ;i++) {
		cin >> h >> w >> n;
		if (n % h == 0) {
			floor = h;
			room = n / h;
		}
		else {
			floor = n % h;
			room = n / h + 1;
		}
		if (room < 10)
			cout << floor << "0" << room << '\n';
		else
			cout << floor << room << '\n';
	}
	
}
