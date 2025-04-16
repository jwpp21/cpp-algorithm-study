////#include <iostream>
////#include <cstdlib>
////using namespace std;
////#define MAX_QUEUE_SIZE 5
////
////typedef struct {
////	int id;
////	int arrival_time;
////	int service_time;
////}element;
////
////typedef struct {
////	element data[MAX_QUEUE_SIZE];
////	int front, rear;
////}QueueType;
////
////void init_queue(QueueType* q) {
////	q->front = 0;
////	q->rear = 0;
////}
////int isEmpty(QueueType* q) {
////	return (q->rear == q->front);
////}
////int isFull(QueueType* q) {
////	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
////}
//////void queue_print(QueueType* q) {
//////	cout << "QUEUE(front=" << q->front << " rear=" << q->rear << ") = ";
//////	if (!isEmpty(q)) {
//////		int i = q->front;
//////		do {
//////			i = (i + 1) % MAX_QUEUE_SIZE;
//////			cout << q->data[i] << " | ";
//////			if (i == q->rear)
//////				break;
//////
//////		} while (i != q->front);
//////	}
//////	cout << endl;
//////}
////
////void enqueue(QueueType* q, element item) {
////	if (isFull(q)) {
////		cout << "��ȭ" << endl;
////		exit(1);
////	}
////	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
////	q->data[q->rear] = item;
////}
////element dequeue(QueueType* q) {
////	if (isEmpty(q)) {
////		cout << "����" << endl; 
////		exit(1);
////	}
////	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
////	return q->data[q->front];
////}
////element peek(QueueType* q) {
////	if (isEmpty(q)) {
////		cout << "����" << endl;
////		exit(1);
////	}
////	return q->data[q->rear];
////}
//int main() {
//	int minutes = 60;
//	int total_wait = 0;
//	int total_customers = 0;
//	int service_time = 0;
//	int service_customer=0;
//	QueueType queue;
//	init_queue(&queue);
//
//	srand(time(NULL));
//	for (int clock = 0;clock < minutes;clock++) {
//		cout << "����ð�: " << clock << endl;
//		if (rand() % 10 < 3) {
//			element customer;
//			customer.id = total_customers++;
//			customer.arrival_time = clock;
//			customer.service_time = rand() % 3 + 1;
//			enqueue(&queue, customer);
//
//			cout << "�� " << customer.id << "�� " << customer.arrival_time << "�� ����. ����ó���ð� = " << customer.service_time;
//
//		}
//		if (service_time > 0) {
//			cout << service_customer << " ���� ó����.";
//			service_time--;
//		}
//		else {
//			if (!isEmpty(&queue)) {
//				element customer = dequeue(&queue);
//				service_time = customer.id;
//				service_time = customer.service_time;
//				cout << "�� " << customer.id << "�� " << clock << "�� ���� ������. ���ð��� " << clock - customer.arrival_time << endl;
//				total_wait += clock - customer.arrival_time;
//			}
//		}
//	}
//	cout << "��ü ��� �ð� = " << total_wait;
//	return 0;
//}