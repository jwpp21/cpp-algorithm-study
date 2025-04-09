#include <iostream>
using namespace std;


int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else
		return n*factorial(n - 1);
}
int sum(int n) {
	if (n <= 1) return 1;
	else
		return n + sum(n - 1);
}
double sum2(double n) {
	if (n == 1) return 1;
	else
		return 1/n + sum2(1 / (n - 1));
}
int Ackermann(int m, int n) {
	if (m == 0) return n + 1;
	else if (n == 0) return Ackermann(m - 1, 1);
	else {
		return Ackermann(m - 2, Ackermann(m, n - 1));
	}
}

void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		cout << "원판 " << n << "을 " << from << "에서 " << to << "로 옮긴다." << endl;
 	}
	else {
		hanoi(n - 1, from, to, tmp);
		cout << "원판 " << n << "을 " << from << "에서 " << to << "로 옮긴다." << endl;
		hanoi(n - 1, tmp, from, to);
	}
}
int main() {
	hanoi(4, 'A', 'B', 'C');
}