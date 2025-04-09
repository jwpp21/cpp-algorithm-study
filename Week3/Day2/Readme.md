
### 4월 9일 학습 기록
---

#### 학습 내용
- 배열, 구조체, 포인터
- 순차 탐색, 이진 탐색

#### 개념 정리
##### 배열
- 동일한 타입의 데이터를 한 번에 여러개 만들 때 사용하는 데이터타입
- 배열의 선언법 ex) int list[7];
- 2차원 배열 ex) int list[3][7];
- 배열의 연산 >>> 생성, get(list, i), set(list, i, value)

##### 구조체
- 다양한 타입의 데이터들을 한곳에 묶는 방법
- 선언 ex) struct student { int i; char name[20]; double x; };
- 구조체를 실 생성 ex) student s;

##### 배열의 응용 - 다항식
```
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {          // 다항식 구조체 타입 선언
    int degree;         // 다항식의 차수
    int coef[MAX_DEGREE];   // 다항식의 계수
} polynomial;
// 
double eval(polynomial p, double a) {
    double result = 1;
    double aa = 0;
    for (int i = 0; i <= p.degree; i++) {
        if (p.coef[i] != 0) {
            for (int j = p.degree - i; j > 0; j--) {
                result = result * a;
            }
            p.coef[i] = result * p.coef[i];
            aa = aa + p.coef[i];
            result = 1;
        }
    }
    return aa;
}
polynomial poly_add1(polynomial A, polynomial B)  // C=A+B
{
    polynomial C;            // 결과 다항식
    int Apos = 0, Bpos = 0, Cpos = 0;   // 배열 인덱스 변수
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

    while (Apos <= A.degree && Bpos <= B.degree) {
        if (degree_a > degree_b) {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

void print_poly(polynomial a)
{
    for (int i = 0; i <= a.degree; i++)
        if (a.coef[i] != 0) {
            if (a.degree != i)
                printf("%dx^%d + ", a.coef[i], a.degree - i);
            else
                printf("%d", a.coef[i]);
        }
    printf("\n");
}


// 주함수
void main()
{
    polynomial a = { 5, {10, 0, 0, 0, 6, 1} };
    polynomial b = { 4,    {7, 0, 5, 0, 1} };

    print_poly(a);
    double r = eval(a, 2.5);
    printf("%.lf\n", r);

    print_poly(b);
    polynomial c;
    c = poly_add1(a, b);
    print_poly(c);
}
```
