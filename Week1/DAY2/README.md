
### 3월 10일 학습 기록
---

#### 학습 내용
- 객체 포인터, 객체 배열, 동적 메모리 할당 및 반환, 객체와 객체 배열의 동적 생성 및 반환
- this 포인터
- string 클래스를 이용한 문자열 사용
- 포인터와 참조자 개념 학습

#### 문제 풀이
1. [백준 11720 형변환] https://www.acmicpc.net/problem/11720
   - 주요 개념: 형변환
   - 코드 흐름 설명: string str 문자열 변수에 한줄로 숫자가 입력됨. 그 문자열인 숫자를 한자릿 수 씩 더해서 값 구하는 문제
   - 어려웠던 점 string 변수를 str[0] <<< 이런식으로 변환하면 char 형태가 됨. 그래서 stoi(str[0])는 틀린 표현.
   - 그래서 <b>str[0] - '0'<b>을 해주면 char to int로 형변환 됨.
   - 개선할 점 X
2. [백준 10809 문자열] https://www.acmicpc.net/problem/10809
   - 주요 개념: 배열 초기화, 아스키코드 활용한 배열 인덱스 찾기
   - 코드 흐름: ex) baekjoon이면 크기가 26이면서 알파벳을 나타내는 result 배열에 입력받은 문자열의 각 알파벳이 인덱스 몇번째에 있는지 ex) b -> 1 a->0 e->4
   - 어려웠던점 ASCII코드를 활용해서 string 변수를 int index = s[0] - 'a' << 이런식으로 진행하면 인덱스가 나옴. 그렇게되면 result[index] = i <<< 이렇게 쉽게 진행
  
`#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int res[26]; // 26개의 알파벳을 저장할 배열
    fill(res, res + 26, -1); // 모든 값을 -1로 초기화

    // 문자열을 순회하면서 첫 등장 위치 저장
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a'; // 'a'를 0, 'b'를 1, ..., 'z'를 25로 변환
        if (res[index] == -1) { // 첫 등장한 경우에만 저장
            res[index] = i;
        }
    }

    // 결과 출력
    for (int i = 0; i < 26; i++) {
        cout << res[i] << " ";
    }

    return 0;
}`

---

✅ 오늘의 목표 달성!
💪 내일 목표: stactic 멤버
