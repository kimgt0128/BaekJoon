#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string expr;
    cin >> expr;

    vector<double> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    stack<double> st;
    for (char ch : expr) {
        if ('A' <= ch && ch <= 'Z') {
            st.push(values[ch - 'A']);
        } else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double res = 0;
            if (ch == '+') res = a + b;
            else if (ch == '-') res = a - b;
            else if (ch == '*') res = a * b;
            else if (ch == '/') res = a / b;
            st.push(res);
        }
    }
    cout.precision(2);
    cout << fixed << st.top() << endl;
    return 0;
}
