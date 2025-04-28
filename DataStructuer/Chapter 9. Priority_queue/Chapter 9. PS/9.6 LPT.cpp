(LPT >>> Longest pro-cessing time first)
#define JOBS 7
#define MACHINES 3
int main(void)
{
	int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 }; // 작업은 정렬되어 있다고 가정
	element m = { 0, 0 }; // m.id , m.avail
	HeapType* h;
	h = create();
	init(h);
	// avail 값은 기계가 사용 가능하게 되는 시간
	for (int i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < JOBS; i++) {
		m = delete_min_heap(h);
		printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당합니다.\n",
			i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	return 0;
}
/*
JOB 0을 시간=0부터 시간=7까지 기계 1번에 할당합니다.
JOB 1을 시간=0부터 시간=6까지 기계 2번에 할당합니다.
JOB 2을 시간=0부터 시간=5까지 기계 3번에 할당합니다.
JOB 3을 시간=6부터 시간=10까지 기계 3번에 할당합니다.
JOB 4을 시간=7부터 시간=9까지 기계 2번에 할당합니다.
JOB 5을 시간=8부터 시간=9까지 기계 1번에 할당합니다.
JOB 6을 시간=10부터 시간=10까지 기계 2번에 할당합니다.
*/
