#include <iostream>
using namespace std;
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}
void delete3(StackType* s) {
	free(s);
}
int isEmpty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element n) {
	if (is_full(s)) {
		cout << "error";
		exit(1);
	}
	else s->data[++(s->top)] = n;
}
element pop(StackType* s) {
	if (isEmpty(s)) {
		cout << "error";
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (isEmpty(s)) {
		cout << "error" << endl;
		exit(1);
	}
	else return s->data[s->top];
}
//4-11
void count(string s) {
	StackType t;
	init_stack(&t);
	int count = 1;
	for (int i = 0;i < s.length();i++) {
		if (s[i] == '(') {
			cout << count << " ";
			push(&t, count);
			count++;
		}
		else if (s[i] == ')') {
			cout << pop(&t) << " ";
		}
	}
}
//4-12
void press(string t) {
	StackType s;
	init_stack(&s);
	char ch, out=' '; int count = 0;

	for (int i = 0;i < t.length();i++) {
		ch = tolower(t[i]);
		
		if (isEmpty(&s) || (ch == peek(&s))) {
			push(&s, ch);
			count++;
		}
		else {
			while (!isEmpty(&s))
				out = pop(&s);
			cout << count << out;
			push(&s, ch);
			count = 1;
		}
	}
	cout << count << pop(&s);
}
// 4-13
void remove(string t) {
	StackType s;
	init_stack(&s);
	char ch;
	for (int i = t.length() - 1;i >= 0;i--) {
		ch = t[i];
		if (isEmpty(&s)) {
			push(&s, ch);
		}
		if (ch != peek(&s)) {
			push(&s, ch);
		}
	}
	while (!isEmpty(&s)) {
		cout << pop(&s);
	}
}
//4-16
void pelindrome(string t) {
	StackType s;
	init_stack(&s);
	int index = 0;
	for (int i = 0;i < t.length();i++) {
		if (isalpha(t[i])) {
			t[index++] = t[i];
		}
		t[i]=tolower(t[i]);
	}
	for (int i = 0;i < index;i++) {
		push(&s, t[i]);
	}
	index = 0;
	while (!isEmpty(&s)) {
		if (t[index++] != pop(&s)) {
			cout << "회문 아님." << endl;
			exit(1);
		}
	}
	cout << "회문";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string t;
	cin >> t;

	pelindrome(t);
}