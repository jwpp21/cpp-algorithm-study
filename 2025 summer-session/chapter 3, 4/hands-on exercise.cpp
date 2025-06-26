#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// 3-2번
class Date {
	int year, month, day;
public:
	Date(int year, int month, int day);
	Date(string s);
	int getYear();
	int getMonth();
	int getDay();
	void show();
};

Date::Date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(string s) {
	string t;
	for (int i = 0;i < s.length();i++) {
		if (s[i] = '/') {
			
		}
		t[i] = s[i];
	}
}
int Date::getYear() {
	return this->year;
	
}
int Date::getMonth() {
	return this->month;
}
int Date::getDay() {
	return this->day;
}
void Date::show() {
	cout << this->year << "년" << this->month << "월" << this->day << "일" << endl;
}
---------------------------------------------------------------------------------------------- -
3-3번
class Account {
	int id, balance;
	string name;
public:
	Account(string name, int id, int balance);
	void deposit(int cash);
	string getOwner();
	void withdraw(int cash);
	int inquiry();
};
Account::Account(string name, int id, int balance) {
	this->name = name;
	this->id = id;
	this->balance = balance;
}
void Account::deposit(int cash) {
	this->balance += cash;
}
string Account::getOwner() {
	return this->name;
}
int Account::inquiry() {
	return this->balance;
}
void Account::withdraw(int cash) {
	this->balance -= cash;
}
---------------------------------------------------------------------------------------------- -
3-5번
class Random {
public:
	int next();
	int nextInRange(int x, int y);

};
int Random::next() {
	while (true) {
		int tmp = rand();
		if (tmp % 2 == 0)
			return tmp;
	}
}
int Random::nextInRange(int x, int y) {

	while (true) {
		int tmp = rand() % (y - 1) + x;
		if (tmp % 2 != 0) {
			return tmp;
		}
	}
}
---------------------------------------------------------------------------------------------- -
3-9번 
class Oval {
	~Oval();
};
Oval::~Oval() {

}
---------------------------------------------------------------------------------------------- -
3-11번
class Box {
	int width, height;
	char fill;
public:
	Box(int w, int h) { setSize(w, h); fill = '*'; }
	void setFill(char f) { fill = f; }
	void setSize(int w, int h) { width = w; height = h;}
	void draw();
};
void Box::draw() {
	for (int n = 0;n < height;n++) {
		for (int m = 0;m < width;m++) cout << fill;
		cout << endl;
	}
}
---------------------------------------------------------------------------------------------- -
4-5번
int main() {
	cout << "한줄입력(exit)입력시 종료" << endl;
	while (true) {
		string str;
		string s = "abcdefghijklmnopqrstuvwxyz";
		getline(cin, str);
		if (str == "exit") break;
		srand((unsigned)time(0));
		int n = rand() % str.size();
		int k = rand() % 26;
		while (str[n] != ' ') {
			n = rand() % str.size();
		}
		str[n] = s[k];
		cout << str;
	}
}
---------------------------------------------------------------------------------------------- -
4-6번
int main() {
	cout << "한줄입력(exit)입력시 종료" << endl;
	while (true) {
		string str;
		getline(cin, str);
		if (str == "exit") break;
		string res;
		for (int i = str.size()-1;i >= 0;i--) {
			string substr = str.substr(i, 1);
			res += substr;
		}
		cout << res;
		res = "";
	}
}
---------------------------------------------------------------------------------------------- -
4-7, 4-8번
class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
};
void Circle::setRadius(int radius) {
	this->radius = radius;
}
double Circle::getArea() {
	return 3.14 * this->radius * this->radius;
}
int main() {
	int n;
	cin >> n;
	Circle* p = new Circle[n];
	for (int i = 0;i < n;i++) {
		int r;
		cin >> r;
		p[i].setRadius(r);
	}
	int count = 0;
	for (int i = 0;i < n;i++) {
		if (p[i].getArea() > 100) count++;
	}
	cout << count;
}
---------------------------------------------------------------------------------------------- -
 4-9번
class Person {
	string name;
	string tel;
public:
	Person() { ;  }
	string getName() { return this->name; }
	string getTel() { return this->tel; }
	void set(string name, string tel);
	string searchTel(string name);
};

void Person::set(string name, string tel) {
	this->name = name; this->tel = tel;
}

int main() {
	Person* p = new Person[3];

	cout << "이름, 전화번호 입력" << endl;
	for (int i = 1;i <= 3;i++) {
		string name, tel;
		cout << "사람 " << i << ">>";
		cin >> name >> tel;
		p[i - 1].set(name, tel);
	}
	for (int i = 0;i < 3;i++) {
		cout << p[i].getName() << " ";
	}
	cout << endl;
	string wannaTel;
	cout << "전번 검색, 이름입력>> ";
	cin >> wannaTel;
	for (int i = 0;i < 3;i++) {
		if (p[i].getName() == wannaTel) cout << p[i].getTel();
	}
	
}
---------------------------------------------------------------------------------------------- -
 4-10번
class Person {
	string name;
public:
	Person() { ;  }
	Person(string name) { this->name = name; }
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
};

class Family {
	string name;
	Person* p;
	int size;
public:
	Family(string name, int size);
	void setName(int id, string name) { p[id].setName(name); }
	void show();
	~Family() { delete[] p; }
};

Family::Family(string name, int size) {
	p = new Person[size];
	this->size = size;
	this->name = name;
}

void Family::show() {
	cout << this->name << "의 가족은 다음과 같이 3명입니다." << endl;
	for (int i = 0;i < size;i++) {
		cout << p[i].getName() << "\t";
	}
}
int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}
-----------------------------------------------------------------------------------------------
4-12번
class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; }
	double getArea() { return radius * radius * 3.14; }
	string getName() { return name; }
};

class CircleManager {
	Circle* p;
	int size;
	int radius;
public:
	CircleManager(int size);
	~CircleManager() { delete[] p; }
	void searchByName();
	void searchByArea();
};
CircleManager::CircleManager(int size) {
	p = new Circle[size];
	this->size = size;
	for (int i = 0;i < size;i++) {
		string name;
		cout << "원 " << i + 1 << " 이름 반지름 입력: ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}

}
void CircleManager::searchByName() {
	string name;
	cout << "검색하고자하는 원의 이름>>";
	cin >> name;
	for (int i = 0;i < size;i++) {
		if (p[i].getName() == name) cout << p[i].getArea();
	}
}
void CircleManager::searchByArea() {
	int area;
	cout << "최소면적을 정수로 입력>>";
	cin >> area;
	cout << area << "보다 큰 원 탐색";
	for (int i = 0;i < size;i++) {
		if (p[i].getArea() > area)
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << " ";
	}
}
int main() {
	int n;
	cin >> n;
	CircleManager cir(n);
	cir.searchByName();
	cir.searchByArea();
}
