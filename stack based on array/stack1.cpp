// stack1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include<string>
template <class T>
class stack {
    int top = -1;
    T arr[100];
    bool IsEmpty() {
       return top==-1;
    }
public :
    void push(T x) {
        if (top >= 99) { cout << "stack is full"; return; };
        top++;
        arr[top] = x;
    }
    void pop() {
        if (!IsEmpty())
        {
        top--;

        }
        else
        {
            cout << "Stack is empty..!\n";
        }
    }
    T popWithval() {
        if (IsEmpty()) { return NULL; }
        else{
        T lastVal;
        lastVal = arr[top];
        top--;
        return lastVal;
        }
    }
    void getTop() {
        if (IsEmpty()) { cout << "stack is empty"; return; }
        else
            cout << "top is " << top << " and the val is " << arr[top];
    }
    void print() {
        if (IsEmpty()) {
            cout << "nothing to print\n";
            return;
        }
        else {
            cout << " [ ";
            for (int i = top;i > -1;i--) {
                cout<<arr[i] << " , ";
            }
            cout << "\b\b]\n ";
        }
       
    }
};
int main()
{
    stack <int> s;
   
    s.pop();
     
    s.print();
  
  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
