#include <iostream>
#include <string>
using namespace std;

class Hash{
private:
    static const int tableSize = 20;
    typedef struct item{
        string name;
        string drink;
        item* next;
    };
    item* hashTable[tableSize];

public:
    Hash();
    int hash(string key); // index값을 return하는 해시함수
    void addItem(string name, string drink); // key 추가
    int numberOfItemsInIndex(int index);
    void printTable();
    void printItemsInIndex(int index);
    void findDrink(string name);
    void removeItem(string name);
};

Hash :: Hash(){
    for(int i=0; i<tableSize; i++){
        hashTable[i] = new item;
        hashTable[i]->name = "empty";
        hashTable[i]->drink = "empty";
        hashTable[i]->next = NULL;
    }
}

int Hash :: hash(string key){
    int hash = 0;
    int index;

    for(int i = 0; i<key.length(); i++){
        hash = hash + (int)key[i];
    }

    index = hash % tableSize;
    return index;
}

void Hash :: findDrink(string name_){
    int index = hash(name_);
    bool foundName = false;
    string drink_;

    item* ptr = hashTable[index];
    while(ptr != NULL){
        if(ptr->name == name_){
            foundName = true;
            drink_ = ptr -> drink;
        }
        ptr = ptr->next;
    }
    if(foundName == true) {
        cout << "좋아하는 음료는 : " << drink_ << endl;
    } else{
        cout << "음료를 찾지 못했어어요" << endl;
    }
}

void Hash :: addItem(string name_, string drink_){
    int index = hash(name_);

    if(hashTable[index] -> name == "empty"){
        hashTable[index] -> name = name_;
        hashTable[index] -> drink = drink_;
        hashTable[index] -> next = NULL; // ??
    } else{
        item* ptr = hashTable[index];
        item* n = new item;

        n->name = name_;
        n->drink = drink_;
        n->next = NULL;

        while(ptr -> next != NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

int Hash :: numberOfItemsInIndex(int index){
    int count = 0;
    if(hashTable[index] -> name == "empty"){
        return count;
    }
    else {
        count++;
        item* ptr = hashTable[index];
        while(ptr->next != NULL){
            count++;
            ptr = ptr->next;
        }
    }
    cout << "count : " << count << endl;
    return count;
}

void Hash :: printTable(){
    int number;
    for(int i=0; i<tableSize; i++){
        number = numberOfItemsInIndex(i);
        cout << "--------------------------\n";
        cout << "index = " << i << endl;
        cout << hashTable[i] -> name << endl;
        cout << hashTable[i] -> drink << endl;
        cout << "A number of items : " << number << endl;
    }
}

void Hash :: printItemsInIndex(int index){
    item* ptr = hashTable[index];
    if(ptr->name == "empty"){
        cout << "index = " << index << "is empty";
    } else {
        cout << "index " << index << " contains the following item" << endl;
        while(ptr != NULL){
            cout << "---------------------\n";
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "---------------------\n";
            ptr = ptr->next;
        }
    }

}

void Hash :: removeItem(string name_){
    int index = hash(name_);
    item* delPtr;
    item* P1; item* P2;

    // case1 : Bucket is empty
    if(hashTable[index]->name == "empty" && hashTable[index]->drink == "empty"){
        cout << name_ << " was not founded in table" << endl;
    }

    // case2 : only 1 item contained in bucket & that item has matching name
    else if(hashTable[index]->name == name_ && hashTable[index]->next == NULL) {
        hashTable[index]->name = "empty";
        hashTable[index]->drink = "empty";
    }

    // case3 : match is located in the first item in the bucket but there are more items in the bucket.
    else if(hashTable[index]->name == name_){
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete delPtr;

        cout << name_ << " was removed from the hash table \n";
    }

    // Case4 : bucket contains items but first item is not a match
    else {
        P1 = hashTable[index]->next;
        P2 = hashTable[index];

        while(P1 != NULL && P1->name != name_){
            P2 = P1;
            P1 = P1->next;
        }

        // case 3.1 : no match
        if(P1 == NULL){
            cout << name_ << "was not found in the hash table\n";
        }

        // case 3.2 : match is founded
        else{
            delPtr = P1;
            P1 = P1 -> next;
            P2->next = P1;

            delete delPtr;
            cout << name_ << " was removed from the hash table\n";
        }
    }
}

int main() {
    Hash hashy;
    string name = "";
    hashy.addItem("James", "Americano");
    hashy.addItem("Jimmy", "Coke");
    hashy.addItem("Stephen", "Beer");
    hashy.addItem("Klay", "Cider");
    hashy.addItem("Kevin", "smoothie");

    hashy.removeItem("James");
    hashy.printTable();
    hashy.findDrink("Stephen");
    hashy.numberOfItemsInIndex(18);
    hashy.printItemsInIndex(18);
    return 0;
}
