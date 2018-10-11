#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;
    

    LinkedList();
    ~LinkedList();
    Node *  Insert(int index, int data);
    int Delete(int x);
    void print();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

Node* LinkedList::Insert(int index, int data){
    
    if (index < 0) return NULL;
    
    int currIndex    =    1;
    Node* currNode    =    head;
    while (currNode && index > currIndex) {
        currNode    =    currNode->next;
        currIndex++;
    }

    if (index > 0 && currNode == NULL) return NULL;
    
    Node* newNode    =    new    Node;
    newNode->data    =    data;
    if (index == 0) {
        newNode->next    =    head;
        head        =    newNode;
        this->length++;
    }
    else {
        newNode->next    =    currNode->next;
        currNode->next    =    newNode;
        this->length++;
    }
    return newNode;

    
    
}

int LinkedList::Delete(int x){
    Node* prevNode = NULL;
    Node* currNode = head;
    int currIndex = 1;
    
    while (currNode && currNode->data != x) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode) {
        if (prevNode){
            prevNode->next = currNode->next;
            delete currNode;
            this->length--;
        }
        else {
            head = currNode->next;
            delete currNode;
            this->length--;
        }
        return currIndex;
    }
    
    return 0;
}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data<<endl;
        head = head->next;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
 
    //list->add(0,rand() % 10);
    list->Insert(0, 11);
    list->Insert(1, 10);
    list->Insert(2, 9);
    list->Insert(3, 8);
    list->Insert(4, 7);
    list->Insert(5, 6);
    list->Insert(6, 5);
    list->Insert(7, 4);
    list->Insert(8, 3);
    list->Insert(9, 2);
    list->Insert(10, 1);
    
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    
    cout << endl;
    
    list->Delete(5);
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    
    cout << endl;
    
    list->Insert(8, 100);
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    
    //delete list;
    
    
    return 0;
}
