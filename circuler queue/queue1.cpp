// queue1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
const int max_size = 5;
template <class t>
class queue {
    int front = 0;
    int rear = max_size - 1;
    int count = 0;
    t arr[max_size];
public:
    void enqueue(t val) {
        if (count == max_size) { 
            cout << "the queue is full !"<<endl;
            return; 
        }
        else
        {
            rear = (rear + 1) % max_size;
            arr[rear] = val;
            count += 1;
        }

    };
    bool isfull() {
        if (count == max_size) return true;
        else return false;
    }
    bool isempty() {
        if (count == 0)return true;
        else return false;
    }
    void dequeue() {
        if (isempty())return;
        else
        {
            front = (front + 1) % max_size;
            count -= 1;
        }
    }
    void getfront() {
        if (isempty()) { cout << "queue is empty\n"; return; }
        cout<<"the front value is : "<< arr[front]<<"\n";
    }
    void getrear() {
        if (isempty()) {
            cout << "queue is empty\n"; 
               return;
        }
        else {
            cout <<"the rare value is : "<< arr[rear]<<endl;
        }
    }
    void getsize() {
       
            cout << " the size is : " << count<<endl;
    }
    void clear() {
        while (count != 0) {
            dequeue();
         }
    }
    void display() {
        if (isempty()) return;
        cout << "[ ";
        for (size_t i = front; i != rear+1; i=(i+1)%max_size)
        {
            cout << arr[i] << " ";
        }
        cout << "]\n";
    }
    int search(t val) {
        if(!isempty()){
        for (int i = front; i != rear + 1;i = (i + 1) % max_size) {
            if (arr[i] == val)return i;
            else continue;
        }
        cout << "we cant find this index of value...!";
        return -1;
     }
        else {
            cout << "the queue is empty..!\n";
            return -1;
        }
    }
};
int main()
{
    queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.clear();
    q.search(1);
}
