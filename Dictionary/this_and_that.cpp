
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

// 특정 진법의 수를 10진법으로 변환 하는법
// ex) 3진법 수 102를 10진법으로 변환
// 1*3의제곱 + 0*3 + 2*3의0승 = 11 <<< 다른 진법도 마찬가지로 변환할 수 있다.

int n,sum=0;
string s;
cin >> s >> n;
for (int i = 0; i < s.size(); i++) {
	if (s[i] >= '0' && s[i] <= '9') {
		sum = sum * n + (s[i] - '0'); // 문자 '0' ~ '9' 까지의 숫자를 정수값으로 변환. 
	}
	else
		sum = sum * n + (s[i] - 'A' + 10); // 문자 'A' ~ 'Z' 까지의 문자를 정수값으로 변환. +10을 하는 이유는 10진수 이상 진법에서는 알파벳 A~Z가 11~35임.
}
cout << sum;

// 형변환
char one = 'A';
char two = '65';

cout << one;		// 출력 : A
cout << two;		// 출력 : A
cout << int(one);	// 출력 : 65

// 계산식을 거치면 int형으로 변환됨
cout << one - two;	// 출력 : 0 (두 문자 사이의 간격)

// 다른 type 변수에 저장하면 해당 type으로 바뀜
int ONE;
ONE = one;	

cout << ONE;		// 출력 : 65

