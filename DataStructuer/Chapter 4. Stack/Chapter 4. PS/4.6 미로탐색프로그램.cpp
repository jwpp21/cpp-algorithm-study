#include <iostream>
using namespace std;
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6


typedef struct {
	short r;
	short c;
} element;
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
	else s->data[++(s->top)] = { n.r, n.c };
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

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e', '0', '1', '0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}



void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	cout << endl;
	for (int r = 0;r < MAZE_SIZE;r++) {
		for (int c = 0;c < MAZE_SIZE;c++) {
			cout << maze[r][c];
		}
		cout << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	StackType s;
	init_stack(&s);

	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);

		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r , c-1);
		push_loc(&s, r , c+1);

		if (isEmpty(&s)) {
			cout << "실패" << endl;
			return 0;
		}
		else
			here = pop(&s);
	}
	cout << "성공" << endl;
	return 0;
}
