#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &str) {
    stack<char> s;

    for (char ch : str) {
        // Opening brackets → push
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // Closing brackets → check
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false; // No opening bracket

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatch
            }
        }
    }

    // If stack is empty → all matched
    return s.empty();
}

int main() {
    string str;
    cout << "Enter a string of brackets: ";
    cin >> str;   

    if (isBalanced(str))
        cout << "Balanced " << endl;
    else
        cout << "Not Balanced " << endl;

    return 0;
}
