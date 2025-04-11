
while(sum!=0) {
	n[sum % 10]++;
	sum /= 10;
}
// 숫자 분해 (1의 자리수 부터)

to_string() // int to string
stoi() // string to int

// 2차원 배열 초기화
int num[10][10] = {0, };

// 2차원 배열 입력 for문 이용
for(int i=0;i<10;i++){
	cin >> num[i]; // num배열 i번째 줄 전부에 입력 ex) 1303입력시 num[0][0] = 1, num[0][1] = 3 
}
