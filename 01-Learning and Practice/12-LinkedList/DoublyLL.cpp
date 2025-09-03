// Design and implement a doubly linked list data structure in C++.
// Requirements:
// It should allow to insert a new element at any position in the list (beginning, middle, or end).
// It should allow to remove an element from any position in the list.
// It should allow to traverse the list forward (from head to tail).
// It should allow to traverse the list backward (from tail to head).
//
#include<iostream>
using namespace std;

class ListNode {
    public:
	int val;
	ListNode* next;
	ListNode* prev;
	
	ListNode(int data) : val(data), next(nullptr), prev(nullptr){}
	ListNode(int data, ListNode* nextPtr) : val(data), next(nextPtr), prev(nullptr){}
};

ListNode* tail;

ListNode* getTail(){
    return tail;
}

void setTail(ListNode* tailNode){
    tail = tailNode;
}
	
ListNode* insertAtLast(ListNode* head, int data){ // data: 1-> 2
    if(head == nullptr){
        ListNode* newNode = new ListNode(data); // null <- |data| -> null
        head = newNode;
        //tail = newNode; // Initilise tail
        setTail(newNode);
        return head;
    }else{
        ListNode* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        ListNode* newNode = new ListNode(data); // data: 2
        temp->next = newNode;
        newNode->prev = temp;
        // tail = newNode; // Initilise tail
        setTail(newNode);
    }
    return head;
}

void displayListForward(ListNode* head)
{
    ListNode* temp = head;
    cout<<"List: -> ";
    while(temp != nullptr)
    {
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

void displayListBackward(ListNode* head)
{
    ListNode* tailTemp = getTail();
    if(tailTemp != nullptr){
        cout<<"List: ";
        cout<<"NULL <- ";
        while(tailTemp != nullptr)
        {
            cout<<tailTemp->val<<" <- ";
            tailTemp = tailTemp->prev;
        }
    }
    cout<<endl;
}

int getSize(ListNode* head)
{
    ListNode* temp = head;
    int size = 0;
    while(temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

ListNode* deleteAtPos(ListNode* head, int pos){ // data: 1-> 2 -> 3 -> 4
    if(head == nullptr){
        return nullptr;
    }else{
        int size = getSize(head);
        if(pos > size)
            return head;
        else{
            ListNode* temp = head;
            int counter = 1;
            while(temp != nullptr)
            {
                counter++;
                temp = temp->next;
                if(counter == pos)
                {
                    break;
                }
            }
            ListNode* tempNode = temp->prev;
            tempNode->next = temp->next;
            delete temp;
        }
    }
    return head;
}


int main()
{
    ListNode* head = nullptr;
    head = insertAtLast(head, 10);
    head = insertAtLast(head, 20);
    head = insertAtLast(head, 30);
    head = insertAtLast(head, 40);
    head = insertAtLast(head, 50);

    displayListBackward(head);
    displayListForward(head);
    return 0;
}