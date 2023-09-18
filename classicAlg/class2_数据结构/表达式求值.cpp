#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> op_pority{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
stack<char> op_stk;
stack<int> no_stk;

void eval() {
    char op = op_stk.top();
    op_stk.pop();
    int b = no_stk.top();
    no_stk.pop();
    int a = no_stk.top();
    no_stk.pop();
    switch (op) {
        case '+':
            no_stk.push(a + b);
            break;
        case '-':
            no_stk.push(a - b);
            break;
        case '*':
            no_stk.push(a * b);
            break;
        case '/':
            no_stk.push(a / b);
            break;
        default:
            break;
    }
}

int main() {
    string expression;
    cin >> expression;
    int n = expression.size();
    for (int i = 0; i < n; i++) {
        if (isdigit(expression[i])) {
            int x = 0;
            while (i < n && isdigit(expression[i])) {
                x = 10 * x + expression[i] - '0';
                i++;
            }
            no_stk.push(x);
            i--;
        } else if (expression[i] == '(') {
            op_stk.push(expression[i]);
        } else if (expression[i] == ')') {
            while (op_stk.top() != '(') {
                eval();
            }
            op_stk.pop();
        } else {
            // 当后续的op优先级小于等于栈中op时，说明可以计算出栈了，即eval
            // 也因此，op_stk中的优先级一定是递增的
            while (!op_stk.empty() &&
                   op_pority[expression[i]] <= op_pority[op_stk.top()]) {
                eval();
            }
            op_stk.push(expression[i]);
        }
    }
    while (!op_stk.empty()) {
        eval();
    }
    cout << no_stk.top() << endl;
}
