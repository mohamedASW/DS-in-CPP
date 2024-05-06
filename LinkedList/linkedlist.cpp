// linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class t>
class linkedlist {
    struct node {
        t value;
        node* next;
    };
    int length = 0;
    node* head = NULL;
    node* tail = NULL;
public: 
    void Add_In_Front(t val) {
        node* newele = new node;
        newele->value = val;
        if (length == 0) {
            newele->next = NULL;
            head =tail= newele;
        }
        else {
            newele->next = head; 
            head = newele;
        }
        length++;
    }
    void add_to_end(t val) {
        node* newele = new node;
        newele->value = val;
        if (length == 0) {
            newele->next = NULL;
            head = newele;
            tail = newele;
        }
        else {
            newele->next = NULL;
            tail->next = newele;
            tail = newele;
        }
        length++;
    }
    bool isempty() {
        return length == 0;
    }
    void insertWithIndex(int index,t val) {
        if (index == 0) Add_In_Front(val);
        else if (index == length)add_to_end(val);
        else if (index < 0 || index > length) { cout << "out of range\n"; return; }
        else{
        int i = 1;
        node* tmp = head;
        while (i < index) {
            tmp = tmp->next;
            i++;
        }
        node* newele = new node();
        newele->value = val;
        newele->next = tmp->next;
        tmp->next = newele;
        length++;
    }
        
    }
    void display() {
        if (isempty()) {
            cout << "the list is empty ...!\n";
            return;
        }
        cout << "[ ";
        node* tmp = head;
        while (tmp!=NULL) {
            cout << tmp->value<<" ";
            tmp = tmp->next;
        }
        cout << " ]\n";
    }
    void clear() {
        while (head != NULL) {
            node* tmp = head->next;
            delete head;
            head = tmp;
        }
        length = 0;
    }
    void pop() {
        if (isempty()) {
            cout << "the list is empty..!\n";
            return;
        }
        else if (length == 1) {
            delete head;
            head = tail = NULL;
            length--;
            return;
        }
        node* ptr = head;
        for (int i = 1;i < length-1;i++) {
           
            ptr = ptr->next;
        }
        tail  = ptr;
        delete ptr->next;
        ptr->next = NULL;
        length--;
    }
    void shift() {
        if (isempty()) {
            cout << "the list is empty..!\n";
            return;
        }
        else if (length == 1) { 
            delete head; 
            head = tail = NULL;
            length--;
            return;
        }
        node* ptr= head;
        head = head->next;
        delete ptr;
        length--;
    }
    void pop_index(int index) {
        if (isempty()) {
            cout << "the list is empty..!\n";
            return;
        }
        else if (index<0 || index>=length) {
            cout << "out of range\n";
        }
        else if (index == length-1) pop();
        else{
        node* ptr1 = head->next;
        node* ptr2 = head;
        for (int i = 1;i < index;i++) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr1->next;
        delete ptr1;
        length--;
    }
    }
    void getlen() {
        cout << "  length : " << length<<endl;
    }
    void reverseList() {
       
            node* cur = head;
            tail = head;
            node* prev = NULL;
            head = head->next;
            cur->next = prev;
            prev = cur;
            cur = head;
            while (head->next!=NULL) {
                head = head->next;
                cur->next = prev;
                prev = cur;
                cur = head;
            }
            head->next = prev;
    }
    void lastelement() {
        cout << "last element is : " << tail->value<<endl;
    }
    void getfirst() {
        cout << "the first element is : " << head->value<<endl;
     }
    int search(t val) {
        node* cur = head;
        int pos = -1;
        while (cur!= NULL) {
            pos++; 
            if (cur->value == val) return pos;
            cur = cur->next;
        }
        return -1;
    }
};
int main()
{
    linkedlist<int> List;
    List.Add_In_Front(10);
    List.Add_In_Front(20);
    List.Add_In_Front(30);
    List.Add_In_Front(40);
    List.insertWithIndex(2, 25);
    List.shift();
    List.display();
  
}

