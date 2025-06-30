5-1 ~ 5-8
#include <iostream>
#include <string>
using namespace std;

void half(double& n) {
	n /= 2;
}
void combine(string &a, string& b, string& c) {
	c = a + " " + b;
}
bool bigger(int a, int b, int& big) {
	if (a == b) {
		big = a;
		return true;
	}

	else {
		big = max(a, b);
		return false;
	}
}
class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }

};

void increaseBy(Circle &a, Circle& b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

char& find(char a[], char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
	success = false;
}
class MyIntStack {
	int* p;
	int size;
	int tos;
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack() { delete[] p; }
	bool push(int n);
	bool pop(int& n);

};
MyIntStack::MyIntStack() {
	tos = 0;
}
MyIntStack::MyIntStack(int size) {
	this->size = size;
	tos = 0;
	p = new int[size];

}
MyIntStack::MyIntStack(const MyIntStack& s) {
	this->size = s.size;
	this->tos = s.tos;
	this->p = new int[s.size];
	for (int i = 0; i < s.tos; i++) {
		this->p[i] = s.p[i];
	}
}
bool MyIntStack::push(int n) {
	if (tos > size)
		return false;
	else {
		p[tos] = n;
		tos++;
		return true;
	}
}
bool MyIntStack::pop(int& n)
{
	tos--;
	if (tos < 0)
		return false;
	else
	{
		n = p[tos];
		return true;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}
