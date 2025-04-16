### 스택
- 후입선출 자료구조
- 스택의 입출력은 맨 위에서만 일어남.
- 스택은 특히 자료의 출력순서가 입력순서의 역순으로 이뤄져야 할 경우에 긴요하게 사용됨.
- ex) 함수호출을 할 때 스택이 사용됨. 함수는 실행이 끝나면 자신을 호출한 함수로 되돌아가야하는데 이 때 스택은 복귀할 주소를 기억하는데 사용됨.
- tmi: 시스템 스택(운영체제가 사용하는 스택)에서 함수가 호출될 때 마다 활성레코드가 만들어지며 여기에 복귀 주소가 저장됨.


- 스택엔 push, pop 두가지 연산이 존재함.
- 배열을 통해 구현해볼거고 top변수는 항상 스택의 제일 윗 값의 위치를 나타냄. 스택에 아무것도 없다면 top은 항상 -1

```
#define MAX_STACK_SIZE 100

typedef int element;
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
```
