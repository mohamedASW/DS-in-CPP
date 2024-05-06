// infix to postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include <stack>
using namespace std;
int priorty(char x) {
	if (x == '*' || x == '/') return 2;
	else if (x == '+' || x == '-') return 1;
	else if (x == '^') return 3;
	else return 0;
}
string convert(string exp) {
	stack <char> s;
	string str = "";   
	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == ' ' || exp[i] == ',')continue;
	 	else if (isdigit(exp[i]) || isalpha(exp[i])) 
			str += exp[i];
		else if (exp[i] == '(') 
			s.push(exp[i]);
		else if (exp[i] == ')') {
			while (s.top() != '(') {
				str += s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			while (!s.empty() && priorty(exp[i]) <= priorty(s.top())) {
				str += s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
	}
	while (!s.empty()) {
		str += s.top();
		s.pop();
	}
	return str;
}
int main() {
	string ex = "(3+2)*5/2^2";
	cout << convert(ex);

}