// stack2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
template <class T>
class stack2 {
    struct node {
        T val;
        node* next;
    };
    
    node* top=NULL;
    node* tmp = top;
public:
    stack2()
    {
        top = NULL;
        tmp = NULL;
    }
    void push(T newItem) {
        node* ele = new node;
        ele->val = newItem;
        ele->next = top;
        top = ele;
    };
    void pop() {
        if (top == NULL) {
            cout << "stack is empty";
            return;
        }
        tmp = top;
        top = top->next;
        delete tmp;
    };
    void popWithVal(T& container) {
        if (top == NULL) {
            cout << "stack is empty";
            return;
        }

        tmp = top;
        top = top->next;
        container = tmp->val;
        delete tmp;
    };
    T getTop() {
        if (top == NULL) {
            cout << " stack is empty";
            return 0;
        }
        else {
            return top->val;
        };

    };
    void print() {
        if (top == NULL) {
            cout << "\nstack is empty\n";
            return;
        }
        cout << "[";
        while (top != NULL) {
            tmp = top;
            cout << top->val<<" ";
            top = top->next;
            delete tmp;
        } 
        cout << "] \n \n";
    }
};

int main()
{
    stack2<int> stack; 
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    int i;
    stack.popWithVal(i);
    stack.print();
    cout << i << endl;
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
