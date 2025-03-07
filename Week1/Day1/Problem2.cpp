#include <iostream>

using namespace std;

int main() {
	int arr[42] = { 0, };
	int input;
	int count = 0;

	for (int i = 0;i < 10;i++) {
		cin >> input;
		arr[input%42] = 1;
	}
	for (int i = 0; i < 42;i++) {
		if (arr[i] == 1) {
			count++;
		}
	}
	cout << count;
}
git commit -m "[백준 3052 배열 나머지 구하기] https://www.acmicpc.net/problem/3052
