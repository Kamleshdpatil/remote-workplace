#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* link;
    Node(){}
    Node(int n): data(n)
    {
        //cout<<"Stack Node created, with value: "<<data<<endl;
    }
};

class Stack
{
    Node* top;

    public:
    Stack():top(NULL)
    {
        cout<<"Stack created !!"<<endl;
    }

    void Push(int);
    int Pop();
    int Peek();
    bool IsEmpty();
    void Display();
};


int main(void)
{
    Stack stack;
    
    for(int i = 1; i<=5; i++)
    {
        stack.Push(10*i);
    }

    stack.Display();
    cout<<"Peek stack: "<<stack.Peek()<<endl;

    return(0);
}

void Stack::Push(int data)
{
    Node* stackNode = new Node(data);
    if(!stackNode)
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    // Store previous top into new stack node
    stackNode->link = top;

    // Make top to newaly created node 
    top = stackNode;
}

int Stack::Pop()
{
    if(IsEmpty())
    {
        cout<<"\nStack Underflow"<<endl;
        exit(1);
    }
    Node* temp = top;
    top = top->link;
    int popped = temp->data;
    delete temp;
    return popped;
}

int Stack::Peek()
{
    return top->data;
}

bool Stack::IsEmpty()
{
    return NULL == top;
}

void Stack::Display()
{
    cout<<endl;
    if(IsEmpty())
    {
        cout<<"\nStack Underflow"<<endl;
        exit(1);
    }
    else
    {
        Node* temp;
        temp = top;
        while(NULL != temp) 
        { 
            // print top element in stack 
            cout << temp->data <<" ->"; 
            // remove top element in stack 
            //Pop(&root); 
            temp = temp->link;
        } 
    }
    cout<<endl;
}
