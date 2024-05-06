// queue2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
template<class t>
class queue {
    struct node {
        t val;
        node* next;
    };
    node* front = NULL;
    node* rear = NULL;
public :
    bool isempty() {
        return front == NULL;
    }
    void enqueue(t val) {
        if (isempty()) {
            front = new node;
            front->val = val;
            front->next = NULL;
            rear = front;
        }
        else {
            node* newptr = new node;
            newptr->val = val;
            newptr->next = NULL;
            rear->next = newptr;
            rear = newptr;
        }
    }
    void dequeue()
    {
        if (!isempty()) {
        node* temp = front;
        front = front->next;
        delete temp;
        }
        else {
            cout << "the queue is empty ...!\n";
        }
    }
    void getfront() {
        if (!isempty()) {
            cout << "the front value is : " << front->val << endl;
        }
        else cout << " the queue is empty ...!\n";
    }
    void getrear() {
        if (!isempty()) {
            cout << "the rear value is : " << rear->val << endl;
        }
        else cout << " the queue is empty ...!\n";
    }
    int getSize() {
        if (isempty()) return 0;
        int num = 1;
        for (node* count = front;count != rear;count = count->next) {
            num += 1;
        }
        return num;
    }
    void clear() {
        while (front != NULL) {
            node* tmp = front->next;
            delete front;
            front = tmp;
           }
     }
    void display() {
        if (isempty()) { " the queue is empty ...!\n"; return; }
        cout << "[ ";
        for (node* count = front;count != rear;count = count->next) {
            cout << count->val << " ";
        }
        cout << rear->val << " ";
        cout << " ]\n";
    }
};
int main()
{
    queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.getfront();
    q.getrear();
    q.display();
    cout << q.getSize() << endl;
    q.clear();
    if (q.isempty()) cout << "the queue is empty ...!";
    q.getrear();
};