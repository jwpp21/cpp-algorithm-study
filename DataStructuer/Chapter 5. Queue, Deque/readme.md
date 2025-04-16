### 큐
- 스택과 달리 선입선출 방식. 먼저 들어온애가 먼저 나감
- front(전단)과 rear(후단)으로 나뉨
- front에서 삭제가 이뤄지고 rear에서 삽입이 일어남.
- enqueue, dequeue 연산이 존재. 삽입 삭제임.
- 주로 현실세계의 상황을 시뮬레이션할 때 사용됨. ex) 사람들의 대기열, 공항 이륙 비행기들 등
---

#### 선형큐
- 배열로 구현.
```cpp
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // 선형 큐 타입
	int  front;
	int rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 선형 큐 초기화
void init_queue(QueueType *q)
{
	q->rear = -1;
	q->front = -1;
}
// 선형 큐 상태 출력
void queue_print(QueueType *q)
{
	for (int i = 0; i<MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i> q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
// 선형 큐가 포화상태인가?
int is_full(QueueType *q)
{
	if (q->rear ==  MAX_QUE_SIZE - 1 )
		return 1;
	else
		return 0;
}
// 선형 큐가 공백상태인가?
int is_empty(QueueType *q)
{
	if ( q->front == q->rear )
		return 1;
	else
		return 0;
}
// 선형 큐에 데이터 삽입
void enqueue(QueueType *q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[  ++(q->rear)  ] = item;
}
// 선형 큐에서 데이터 제거
int dequeue(QueueType *q)
{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[ ++(q->front) ];
	return item;
}
```

---
#### 원형큐
- front와 rear의 값이 배열의 끝인 MAX_QUEUE_SIZE-1에 도착하면 다음 값이 0이 되도록 하는 자료구조
- 방법은 front = (front+1) % MAX_QUEUE_SIZE; <<<
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_QUEUE_SIZE 5

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;

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
//void queue_print(QueueType* q) {
//	cout << "QUEUE(front=" << q->front << " rear=" << q->rear << ") = ";
//	if (!isEmpty(q)) {
//		int i = q->front;
//		do {
//			i = (i + 1) % MAX_QUEUE_SIZE;
//			cout << q->data[i] << " | ";
//			if (i == q->rear)
//				break;
//
//		} while (i != q->front);
//	}
//	cout << endl;
//}

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
```

---
### 덱(DEQUE)
- double-ended queue의 줄임말로서 큐의 front,  rear에서 모두 삽입과 삭제가 가능한 큐를 의미함.
- 그러나 여전히 중간에서 삽입 삭제는 불가능.

```cpp
#include <stdio.h>
#define MAX_DEQUE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_DEQUE];
} DequeType;

void init_deque(DequeType *dq)
{
    dq->front = 0;
    dq->rear = 0;
}

int is_empty(DequeType *dq)
{
    if(dq->front == dq->rear)
        return 1; //공백 상태
    else
        return 0;
}

int is_full(DequeType *dq)
{
    if(dq->front == (dq->rear + 1) % MAX_DEQUE)
        return 1; //포화 상태
    else
        return 0;
}

void add_front(DequeType *dq, element item)
{
    if(is_full(dq) == 1){
        printf("full\n");
    }
    else{
        dq->data[dq->front] = item;
        dq->front = (dq->front - 1 + MAX_DEQUE) % MAX_DEQUE;
    }
}

void add_rear(DequeType *dq, element item)
{
    if(is_full(dq) == 1){
        printf("full\n");
    }
    else{
        dq->rear = (dq->rear + 1) % MAX_DEQUE;
        dq->data[dq->rear] = item;
    }
}

int delete_front(DequeType *dq)
{
    if(is_empty(dq) == 1){
        printf("empty\n");
    }
    else{
        dq->front = (dq->front + 1) % MAX_DEQUE;
        return dq->data[dq->front];
    }
}

int delete_rear(DequeType *dq)
{
    element item;
    if(is_empty(dq) == 1){
        printf("empty\n");
    }
    else{
        item = dq->data[dq->rear];
        dq->rear = (dq->rear - 1 + MAX_DEQUE) % MAX_DEQUE;
        return item;
    }
}

int get_front(DequeType *dq)
{
    if(is_empty(dq) == 1){
        printf("empty\n");
    }
    else{
        return dq->data[(dq->front + 1) % MAX_DEQUE];
    }
}

int get_rear(DequeType *dq)
{
    if(is_empty(dq) == 1){
        printf("empty\n");
    }
    else{
        return dq->data[dq->rear];
    }
}

void print_deque(DequeType *dq)
{
    printf("(front = %d rear = %d) = ", dq->front, dq->rear);
    if(!is_empty(dq) == 1){
        int i = dq->front;
        do{
            i = (i + 1) % MAX_DEQUE;
            printf("%d | ", dq->data[i]);
            if(i == dq->rear)
                break;
        } while(i != dq->front);
        printf("\n");
    }
}
```
