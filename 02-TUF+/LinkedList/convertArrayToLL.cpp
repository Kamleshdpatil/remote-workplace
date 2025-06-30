#include<iostream>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node(int value, Node* ptr= nullptr){
        data = value;
        next = ptr;
    }
    // Node(int data){
    //     this->data = data;
    //     next = nullptr;
    // }
};

void insertNewNodeAtLast(Node* head, int data){
    if(head == nullptr){
        head = new Node(data);
        cout<<"Head is created.."<<endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = (temp)->next;
    }
    Node* newNode = new Node(data);
    temp->next = newNode;
    cout<<"Node is created at last with data: "<<data<<endl;
    return;
}

int main()
{
    int arr[]={12, 25, 35, 45, 55};
    int size = sizeof(arr)/sizeof(arr[0]);

    Node* head = new Node(arr[0]);
    for(int i = 1; i < size; i++){
        insertNewNodeAtLast(head, arr[i]);
    }

    cout<<endl;
    cout<<"Linked List head: "<<head->data<<endl;
    Node* temp = head;
    // while (temp != nullptr)
    // {
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = (temp)->next;
    }
    return(0);
}