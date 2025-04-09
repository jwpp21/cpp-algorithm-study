//#include <iostream>
//using namespace std;
//
//typedef struct {
//	int x;
//	string s;
//} prac;
//void insert(int array[], int loc, int value) {
//
//	for (int i = 9;i >loc;i--) {
//		array[i] = array[i - 1];
//	}
//	array[loc] = value;
//}
//
//int delete3(int array[], int loc) {
//	int value = array[loc];
//	for (int i = loc;i < 10;i++) {
//		if (array[i + 1]) break;
//		array[i] = array[i + 1];
//	}
//	return value;
//}
//int main() {
//	int array[10];
//	for (int i = 1;i <= 10;i++) {
//		array[i-1] = i;
//	}
//	insert(array, 3, 10);
//	cout << delete3(array, 3) << endl;
//	for (int i = 1;i <= 10;i++) {
//		cout << array[i - 1] << " ";
//	}
//	prac* a;
//	a = (prac*)(malloc(sizeof(int)));
//
//	a->x = 100;
//	a->s = "just testing";
//
//	free(a);
//}