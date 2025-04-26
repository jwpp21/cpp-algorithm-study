MY ANSWER
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector <int> res(s.length());
    vector<int> v(s.length());
    stack<char> st;
    int answer = 0;
    int idx = 0, vIdx =0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (st.empty())
            {
                cout << "-1";
                return 0;
            }
            else {
                char open_ch = st.top();
                if ((open_ch == '(' && s[i] != ')') ||
                    (open_ch == '[' && s[i] != ']')) {
                    cout << "-1";
                    return 0;
                }
            }
            st.pop();
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (st.empty())
                        answer += 2;
                    else {
                        res[idx] = 2;
                        idx++;
                    }
                }
                else {
                    if (st.empty()) {
                        for (int i = 0;i < idx;i++) {
                            answer += res[i];
                        }
                        answer *= 2;
                        v[vIdx] = answer;
                        vIdx++;
                        answer = 0;
                        for (int i = 0;i < idx;i++) {
                            res[i] = 0;
                        }
                    }
                    else {
                        if (idx > 0) {
                            res[idx - 1] *= 2; 
                        }
                    }
                }
            }
            else {
                if (s[i - 1] == '[') {
                    if (st.empty())
                        answer += 3;
                    else {
                        res[idx] = 3;
                        idx++;
                    }
                }
                else {
                    if (st.empty()) {
                        for (int i = 0;i < idx;i++) {
                            answer += res[i];
                        }
                        answer *= 3;
                        v[vIdx] = answer;
                        vIdx++;
                        answer = 0;
                        for (int i = 0;i < idx;i++) {
                            res[i] = 0;
                        }
                    }
                    else {
                        if (idx > 0) {
                            res[idx - 1] *= 3;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0;i < vIdx;i++) {
        answer += v[i];
    }
    cout << answer << "\n";
    return 0;
}
/* 내 코드에서 틀린 부분
1. st.empty()를 사용해서 계산 타이밍을 잡는 문제
너는 계속 st.empty() 를 이용해서
"스택이 비어있으면 다 계산한다"
이렇게 하고 있는데,
스택이 비었다고 해서 항상 괄호 쌍이 완벽하게 닫힌 건 아냐.
예를 들어
(()())
이런 식으로 안쪽이 닫히고 다시 열릴 수 있어.
즉, 비어있을 때만 처리하면 안 되고, 괄호가 맞춰졌을 때만 그때그때 처리해야 해.

2. res[idx], v[vIdx] 방식이 구조적으로 오류를 만들 수 있어
res, v는 크기만 잡고 직접 인덱스에 값을 넣고 있는데,
이 방식은 idx, vIdx 관리가 조금만 틀려도 값이 꼬인다.
예를 들어, 닫히는 괄호를 만났을 때도, 어떤건 새로운 스코프고 어떤건 안쪽 스코프인데 이걸 구별 못해.
문제는 "중첩 괄호"랑 "연속 괄호"를 다르게 다뤄야 하는데 그걸 이 구조로는 자연스럽게 못 함.

3. 문제 의도 자체는 "괄호 열고 닫을 때마다 계산"하는 것
그냥 "비어있다/안 비어있다"로 따지지 말고
괄호를 열 때는 push
괄호를 닫을 때는
바로 앞이 열린 괄호이면 곱하기
아니면 안쪽 값을 더해서 곱하기 해야 해.

🔥 결론
핵심 틀은 이렇게 해야 해
스택에는 (, [ 또는 숫자값을 같이 넣어야 해
닫는 괄호가 나오면
  만약 스택 위가 숫자면 → 다 꺼내서 합치고 괄호에 맞춰서 곱하기
  만약 스택 위가 열린 괄호라면 → 바로 값 처리
*\

CORRECT ANSWER
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(-1); // '('를 -1로 표시
        }
        else if (s[i] == '[') {
            st.push(-2); // '['를 -2로 표시
        }
        else if (s[i] == ')') {
            int sum = 0;
            while (!st.empty() && st.top() != -1) {
                if (st.top() == -2) { // 잘못된 괄호
                    cout << 0;
                    return 0;
                }
                sum += st.top();
                st.pop();
            }
            if (st.empty()) { // '('를 못 찾음
                cout << 0;
                return 0;
            }
            st.pop(); // '(' 제거
            if (sum == 0) st.push(2); // 바로 짝이 맞으면 2
            else st.push(2 * sum); // 안에 뭔가 있으면 2 * 합
        }
        else if (s[i] == ']') {
            int sum = 0;
            while (!st.empty() && st.top() != -2) {
                if (st.top() == -1) { // 잘못된 괄호
                    cout << 0;
                    return 0;
                }
                sum += st.top();
                st.pop();
            }
            if (st.empty()) { // '['를 못 찾음
                cout << 0;
                return 0;
            }
            st.pop(); // '[' 제거
            if (sum == 0) st.push(3); // 바로 짝이 맞으면 3
            else st.push(3 * sum); // 안에 뭔가 있으면 3 * 합
        }
    }

    int answer = 0;
    while (!st.empty()) {
        if (st.top() < 0) { // 아직 괄호가 남아있으면
            cout << 0;
            return 0;
        }
        answer += st.top();
        st.pop();
    }
    cout << answer;
    return 0;
}
