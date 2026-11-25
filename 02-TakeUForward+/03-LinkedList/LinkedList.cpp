#include<iostream>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node(int value, Node* ptr= NULL){
        data = value;
        next = ptr;
    }
};

int getSize(Node* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    Node* middleOfLinkedList(Node* head) {
        int size = getSize(head);
        if(size == 1){
            return head;
        }
        int count = 0;
        while(head != NULL){
            head = head->next;
            count++;
            if(count == (size/2)){
                return head;
            }
        }
        return head;
    }

void insertNewNodeAtLast(Node* head, int data){
    if(head == NULL){
        head = new Node(data);
        //cout<<"Head is created.."<<endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = (temp)->next;
    }
    Node* newNode = new Node(data);
    temp->next = newNode;
    //cout<<"Node is created at last with data: "<<data<<endl;
    return;
}

Node* convertArrayToLinkedList(Node* head, int arr[], int size){
    if(!head)
        head = new Node(arr[0]);
    
    if(size == 1)
        return head;
    
    Node* temp = head;
    for(int i = 1; i < size; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void Display(Node* head){
    cout<<endl;
    cout<<"Linked List Size: "<<getSize(head)<<endl;
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = (temp)->next;
    }
}

int main()
{
    int arr[]={12, 25, 200, 35, 45, 55};
    int size = sizeof(arr)/sizeof(arr[0]);
    Node* head = NULL;

    head = convertArrayToLinkedList(head, arr, size);

    // Node* middleNode = middleOfLinkedList(head);
    // Display(middleNode);

    Display(head);


    return(0);
}