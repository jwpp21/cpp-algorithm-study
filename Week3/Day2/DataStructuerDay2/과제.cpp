#include <iostream>

using namespace std;

typedef struct student {
	int id;
	double eng;
	double math;
}student;

int get_sum(int eng, int math) {
	int sum = 0;
	sum = eng + math;
	return sum;
}

double get_average(double eng_sum, double math_sum, int size) {
	double avg = 0;
	avg = (eng_sum + math_sum) / size;
	return avg;
}
void get_grade(student *s, int id) {
	int count = 10;
	int max;
	max = s[0].eng + s[0].math;
	int grade;
	for (int i = 0;i < 10;i++) {
		if (s[i].id == id) {
			cout << s[i].id << " " << s[i].eng << " " << s[i].math <<" ";
			grade = s[i].eng + s[i].math;
		}
	}
	for (int i = 0;i < 10;i++) {
		if (max < s[i].eng + s[i].math) {
			max = s[i].eng + s[i].math;
		}
	}
	for (int i = 0;i < 10;i++) {
		if (grade >= s[i].eng + s[i].math) {
			count--;
		}
	}
	cout << count+1 << endl;
}
int main() {
	double eng_average = 0, math_average = 0;
	int eng_sum = 0, math_sum = 0;
	student student[10] = {
		{1234, 78, 87 },
		{1235, 65, 55 },
		{1365, 88, 95 },
		{2546, 45, 56 },
		{3124, 58, 88 },
		{1976, 71, 54 },
		{1657, 32, 55 },
		{2547, 90, 43 },
		{2456, 66, 78 },
		{1765, 54, 99 }
	};
	for (int i = 0;i < 10;i++) {
		eng_sum += get_sum(student[i].eng, 0);
		math_sum += get_sum(0, student[i].math);
	}
	eng_average = get_average(eng_sum, 0, 10);
	math_average = get_average(0, math_sum, 10);

	get_grade(student, student[2].id);
}