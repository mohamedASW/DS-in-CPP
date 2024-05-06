
#include <iostream>
using namespace std;
class Array {
    int max_size;
    int length=0;
    int* arr;
public :
    Array(int size) {
        max_size = size;
        arr = new int[max_size];
    }
    bool isempty() {
        return length == 0;
    }
    bool isful() {
        return length == max_size;
    }
    int getsize() {
      return length;
    }
    void print() {
        if (isempty()) return;
        for (size_t i = 0; i < length; i++)
        {
            cout << arr[i] << " "; 
        }
        cout << "\n";
    }
    void add(int index , int val) {
        if (isful()) cout << "the array is full...!\n";
        else if (index<0 || index>length) cout<<"out of range\n";
        else {
            for (size_t i = length; i >index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = val;
            length++;
        }
    }
    void exchange(int index , int val) {
        if (index<0 || index>=length)cout << "out of range\n";
        arr[index] = val;
    }
    void remove(int index) {
        if (isempty()) cout << "array is empty...!";
        else if (index<0 || index>=length)cout << "out of range\n";
        else{
        for (size_t i = index; i < length-1; i++)
        {
            arr[i] = arr[i + 1];
        }
        length--;
    }
    }
    void addtoend(int val) {
        if (isful())cout << "the array is full\n";
        else
        arr[length++] = val;
    }
    int searchwithvalue(int val) {

        if (isempty()) cout << "the array is empty";
        for (size_t i = 0; i < length; i++)
        {
            if (arr[i] == val)return i;
        }
        return -1;
    }
    void searchwithindex(int index) {
        if (isempty())cout << "the arrary is empty..!\n";
        else if (index < 0 || index >= length) cout << "out of range\n";
        else cout << arr[index];
    }
    void insertnodublicate(int index,int val) {
        if (searchwithvalue(val) == -1) {
            add(index, val);
        }
        else cout << "this value is already exsited...!\n";
    }
    ~Array() {
        delete[]arr;
    }
    void clear() {
        length = 0;
    }
};
int main()
{
    Array ar(100);
    ar.add(0, 1);
    ar.add(1, 2);
    ar.addtoend(3);
    ar.add(3, 5);
    ar.exchange(0, 5);
   cout<<"the size is : " <<ar.getsize() << endl;
    ar.print();
}
