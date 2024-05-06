// balanced branses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<stack>
using namespace std;
bool issame(char x, char y) {
    if (x == '[' && y == ']') return true;
    else if (x == '{' && y == '}')return true;
    else if (x == '(' && y == ')')return true;
    else return false;
}
bool isPair(char top, char close) {
    if ((top == '[' && close == ']') || (top == '{' && close == '}') || (top == '(' && close == ')'))
        return true;
    return false;
}
bool balanced(string exp) {
    stack<char>s;
    for (int i = 0; i < exp.length();i++) {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(') {
            s.push(exp[i]);
        }
        if (!s.empty()&& (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')){
            if (isPair(s.top(),exp[i])) {
                s.pop();
            }
        }

    }
    if (s.empty()) return true;
    else return false;

}
int main()
{
    string expr;
    cout << " enter an  expression : ";
    cin >> expr;
    if (balanced(expr)) cout << " balanced";
    else cout << " not balanced";
}

