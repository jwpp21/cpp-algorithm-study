
### 4월 1일 학습 기록
---

#### 학습 내용
- 선택 정렬, 버블 정렬, 삽입 정렬
- 순차 탐색, 이진 탐색
- 성능 측정, 시간 복잡도 

#### 개념 정리
##### 선택 정렬
- 배열의 size가 적을 때, 클 때 상관없이 min_index를 통해 이중for문을 돌리며 배열의 앞에서부터 최소값으로 채워나가는 정렬.
- 최소값을 가진 인덱스와 배열의 앞 인덱스를 swap() 하며 진행.

```
{
	int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int min_index=0;
	for (int i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (int j = i+1;j < size;j++) {
			if (arr[min_index] > arr[j])
				min_index = j;
		}
		swap(arr[i], arr[min_index]);
		Print(arr, size);

		cout << boolalpha;
		cout << CheckSorted(arr, size);
		cout << endl;

		if (CheckSorted(arr, size) == true)
			break;
	}
}
```
##### 버블 정렬
- 모든 값들을 한번씩 비교 -> 이미 정렬된 배열에 유리함.
- stable함.
###### 버블 정렬 조기 종료 코드 내 구현
```
for (int k = 0;k < n;k++) {
	if (arr[k] == arr[ii++])
		count++;
}
if (count == n)
	break;
```
###### 버블 정렬 단순 구현
```

	for (int i = 0;i < n - 1;i++) {
		bool isSwapped = false
		for (int j = 0;j < n - 1 - i;j++) {
			if (arr1[j] > arr1[j + 1]) {
				swap(arr1[j], arr1[j + 1]);
				isSwapped = true
			}
			Print(arr, n);
	}
	if(!isSwapper)
		break;
	cout << endl;
}
```
---

✅ 오늘의 목표 달성!
💪 내일 목표: 동적 할당
