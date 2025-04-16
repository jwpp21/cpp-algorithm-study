#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}
int isEmpty(QueueType* q) {
	return (q->rear == q->front);
}
int isFull(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q) {
	cout << "QUEUE(front=" << q->front << " rear=" << q->rear << ") = ";
	if (!isEmpty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			cout << q->data[i] << " | ";
			if (i == q->rear)
				break;

		} while (i != q->front);
	}
	cout << endl;
}

void enqueue(QueueType* q, element item) {
	if (isFull(q)) {
		cout << "포화" << endl;
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (isEmpty(q)) {
		cout << "공백" << endl;
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(QueueType* q) {
	if (isEmpty(q)) {
		cout << "공백" << endl;
		exit(1);
	}
	return q->data[q->rear];
}
//3-8
int get_count(QueueType* q) {
	if (q->rear >= q->front) {
		return q->rear - q->front;
	}
	else {
		return (MAX_QUEUE_SIZE - (q->front - q->rear));
	}
}
//3-10
int fib(int n) {
	QueueType q;
	init_queue(&q);
	enqueue(&q, 0);
	enqueue(&q, 1);
	for (int i = 0;i < n;i++) {
		enqueue(&q, dequeue(&q) + peek(&q));
	}
	return peek(&q);
}
//3-11
int check(string s) {
	QueueType q;
	init_queue(&q);

	for (int i = 0;i < s.length();i++) {
		if (isalpha(s[i]))
			enqueue(&q, tolower(s[i]));
	}

	// Queue → 배열로 복사
	int len = (q.rear - q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	char arr[MAX_QUEUE_SIZE];
	int idx = 0;
	int temp_front = q.front;

	while (temp_front != q.rear) {
		temp_front = (temp_front + 1) % MAX_QUEUE_SIZE;
		arr[idx++] = q.data[temp_front];
	}

	// 양 끝에서 회문 검사
	for (int i = 0; i < idx / 2; i++) {
		if (arr[i] != arr[idx - 1 - i])
			return 0;
	}
	return 1;
}

int main() {
	string s;
	cin >> s;

}