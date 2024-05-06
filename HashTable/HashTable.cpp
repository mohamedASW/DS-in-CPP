

#include <iostream>
#include<vector>
using namespace std;
template<typename T>
class Hash {
    struct Entry {
        int Key;
        T  Value;
       Entry* Next;
       Entry(int key,T value){
            Key = key;
            Value = value;
            Next = nullptr;
        }
       Entry() {
           Next = nullptr;
       }
       int GetKey() {
           return Key;
       } 
       T GetValue() {
           return Value;
       }

    };
     int size;
    Entry** HashTable;
    int getHash(int key) {
        return key % size;
    }
    bool checkKey(int key) {
        int index = getHash(key);
        Entry* ptr = HashTable[index];
        while (ptr != nullptr) {
            if (ptr->Key==key)
            {
                return true;
            }
            ptr = ptr->Next;
        }
        return false;
    }
public:
    Hash(int size)
    { 
        this->size = size;
        HashTable = new Entry*[size];
        for (size_t i = 0; i < size; i++)
        {
            HashTable[i] = nullptr;
        }
    }
    void Insert(int key, T value) {
        if (!checkKey(key)) {
        int index = getHash(key);
         
        Entry* newele = new Entry(key, value);
            newele->Next = HashTable[index];
            HashTable[index] = newele;
        }
        else {
            throw exception("you try to insert dublicated key...!");
        }
    }

     vector<T> Get(int key) {
        int index = getHash(key);
        Entry* ptr = HashTable[index];
        vector<T> v;
        while (ptr!=nullptr)
        {
            if (ptr->Key==key)
            {
                v.push_back(ptr->Value);
            }
            ptr = ptr->Next;
        }
        return v;

    }

     void clear() {
         for (size_t i = 0; i < size; i++)
         {
             auto ptr = HashTable[i];
             while (ptr != nullptr) {
                 auto tmp = ptr->Next;
                 delete ptr; 
                 ptr = tmp;
             }
         }
         delete[]HashTable;
     }
    
};




int main()
{
    try
    {
    Hash<string>hash(50);
    hash.Insert(10, "Hossam");
    hash.Insert(60, "Ahmed");
    hash.Insert(110, "Ali");
    hash.clear();
    vector<string> v = hash.Get(10);
    for (auto i : v) {
        cout << i << "  ";
    }
    }
    catch (const std::exception& x)
    {
        cout << x.what();
    }
    
   
	
	
}

