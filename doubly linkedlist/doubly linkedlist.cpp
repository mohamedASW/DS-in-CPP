// doubly linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class t>
class doublylist {
    struct node {
        t value;
        node* post;
        node* pre;
    };
    int index = -1;
    node* head=NULL;
    node* tail = NULL;
public:
    void add_front(t val) {
        node* ele = new node;
        ele->value = val;
        if (index == -1) {
            ele->post = NULL;
            ele->pre = NULL;
            head = tail=ele;
            
        }
        else {
            ele->post = head;
            head->pre = ele;
            ele->pre = NULL;
            head = ele;
            
        }
        index++;
    }
    void add_end(t val) {
        node* ele = new node;
        ele->value = val;
        if (index == -1) {
            ele->post = NULL;
            ele->pre = NULL;
            head =tail = ele;
        }
        else {
            tail->post = ele;
            ele->pre = tail;
            ele->post = NULL;
            tail = ele;
        }
        index++;
    }
    bool isempty() {
        return (head == NULL);
    }
    t get_back(t val) {
        if (isempty()) 
        {

            throw "it is Empty ...! ";
            
        }
        node* cur=head->post; 
        while (cur != NULL) 
        {
            if (cur->value == val) return cur->pre->value;
            cur = cur->post;
        }
        return NULL;
    }
    t get_after(t val) {
        node* cur = head;
        if (isempty()) throw ("It is Empty...!");
        
        while (cur != tail) {
            if ((cur ->value) == val) return cur->post->value;
            cur = cur->post;
        }
        return NULL;
    }
    void getfront() {
        cout << "the front value is : " << head->value<<endl;
    }
    void getlast() {
        cout << "the last value is : " << tail->value << endl;
    }
    void display() {
        if (isempty()) {cout << "the doubly list is empty !"; return; }
        node* cur = head;
        cout << "[";
        while (cur != NULL) {
            cout << cur->value << " ";
            cur = cur->post;
        }
        cout << "]";
    }
    void add_with_index(int index, t val) {
        if (index == 0) add_front(val);
        else if (index<0 || index>this->index) cout << "out of range ...!\n";
        else {
            node* cur = head;
            node* ptr = cur;
            node* newele = new node;
            newele->value = val;
            for (size_t i = 0; i < index; i++)
            {
                cur = cur->post;
                ptr = cur->pre;
            }
            cur->pre = newele;
            newele->post = cur;
            ptr->post = newele;
            newele->pre = ptr;
            this->index++;
        }
    }
    void pop() {
        if (isempty()) {
            cout << "the doubly list is empty ...!";
            return;
        }
        tail = tail->pre;
        delete tail->post;
        tail->post = NULL;
        index--;
    }
    void shift() {
        if (isempty()) {
            cout << "the doubly list is empty ...!";
            return;
        }
        head = head->post;
        delete head->pre;
        head->pre = NULL;
        index--;
    }
    void pop_value(t val) {
        if (isempty()) {
            cout << "the doubly list is empty ...!";
            return;
        }
        node* cur = head;
        while (cur->value != val) {
            cur = cur->post;
        }
        cur->pre->post = cur->post;
        cur->post->pre = cur->pre;
        delete cur;
        index--;
    }
    void clear() {
        node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->post;
            delete temp;
        }
        tail = NULL;
        index = -1;
    }
};
int main()
{  
    doublylist<int> dlist;
    dlist.add_end(10);//0 
    dlist.add_end(10); // 1
    dlist.add_end(30);// 3
    dlist.add_end(40);// 3
    dlist.add_with_index(1, 20);
    dlist.display();
   
}


