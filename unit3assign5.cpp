#include <iostream>
#include <stack>
#include <cctype>  // for isdigit
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;

    for (char ch : expr) {
        // If operand (digit), push to stack
        if (isdigit(ch)) {
            s.push(ch - '0'); // convert char digit to int
        }
        // If operator, pop two elements and apply
        else {
            if (s.size() < 2) {
                cout << "Invalid expression!" << endl;
                return -1;
            }
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break; // assume no divide by zero
                default: 
                    cout << "Unknown operator!" << endl;
                    return -1;
            }
        }
    }

    return s.top(); // Final result
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;

    int result = evaluatePostfix(expr);
    cout << "Result = " << result << endl;

    return 0;
}
