//#include <iostream>
//using namespace std;
//#define MAX_STACK_SIZE 100
//
//typedef char element;
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//}StackType;
//
//void init_stack(StackType* s) {
//	s->top = -1;
//}
//void delete3(StackType* s) {
//	free(s);
//}
//int isEmpty(StackType* s) {
//	return (s->top == -1);
//}
//int is_full(StackType* s) {
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//void push(StackType* s, int n) {
//	if (is_full(s)) {
//		cout << "error";
//		exit(1);
//	}
//	else s->data[++(s->top)] = n;
//}
//element pop(StackType* s) {
//	if (isEmpty(s)) {
//		cout << "error";
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//element peek(StackType* s) {
//	if (isEmpty(s)) {
//		cout << "error" << endl;
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//int checkMatching(const char* in) {
//	StackType* s;
//	char ch, open_ch;
//	int i, n = strlen(in);
//	init_stack(s);
//
//	for (i = 0;i < n;i++) {
//		ch = in[i];
//		switch (ch)
//		{
//		case '(': case '[': case '{':
//			push(s, ch);
//			break;
//		case ')': case ']': case '}':
//			if (isEmpty(s)) return 0;
//			else {
//				open_ch = pop(s);
//				if ((open_ch == '(' && ch != ')') ||
//					(open_ch == '[' && ch != ']') ||
//					(open_ch == '{' && ch != '}')) {
//					return 0;
//				}
//				break;
//			}
//		}
//	}
//	if (!isEmpty(s)) return 0;
//	return 1;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	char* p = "{ A["
//}