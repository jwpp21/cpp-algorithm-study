
### 4월 9일 학습 기록
---

#### 학습 내용
- 배열, 구조체, 포인터
- 동적 메모리 할당당

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
##### 배열의 응용 - 희소행렬
```
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix {
    element data[20];
    int rows;   
    int cols;   
    int terms;  
} SparseMatrix;

void matrix_print(SparseMatrix a) {
    int index = 0;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            int found = 0;
            for (int k = 0; k < a.terms; k++) {
                if (a.data[k].row == i && a.data[k].col == j) {
                    printf("%d ", a.data[k].value);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

SparseMatrix change(SparseMatrix m, int i, int j) {
    if (i < 0 || i >= m.rows || j < 0 || j >= m.rows) {
        printf("잘못된 행 인덱스입니다.\n");
        exit(1);
    }
    for (int k = 0; k < m.terms; k++) {
        if (m.data[k].row == i) {
            m.data[k].row = j;
        }
        else if (m.data[k].row == j) {
            m.data[k].row = i;
        }
    }
    return m;
}

int main() {
    SparseMatrix m1 = {
        { {0, 0, 2}, {0, 2, -3}, {1, 2, 4}, {2, 0, 4}, {2, 1, -2}, {2, 2, 1}, {3, 3, 3} },
        4, 4, 7
    };

    printf("원래 행렬:\n");
    matrix_print(m1);

    int i = 0; 
    int j = 2; 
    SparseMatrix m_changed = change(m1, i, j);

    printf("행 %d과 행 %d을 교환한 후:\n", i, j);
    matrix_print(m_changed);

    return 0;
}
```
##### 포인터
- 포인터는 다른 변수의 주소를 가지고 있는 변수.
- ex) int a = 100; int* p = &a;
- 여기서 &연산자는 주소를 추출하는 연산자이다.
- 예시대로라면 a와 *p는 전적으로 동일하다.

##### 동적 메모리 할당
- 얼마나 많은 메모리를 사용할지 알 수 없기에 사용.
- 운영체제로부터 할당받고 반납함.
- 방법: int* p; p=(int *)malloc(sizeof(int)); <<< 동적 메모리 할당
- *p = 1000; <<< 메모리 사용, free(p); <<< 반납

