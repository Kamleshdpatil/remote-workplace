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
    Node(int n): data(n), link(nullptr){}
};

class Stack
{
    Node* top;

    public:
    Stack():top(NULL)
    {
        cout<<"Stack created !!"<<endl;
    }
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void Push(int);
    int Pop();
    int Peek() const;
    bool IsEmpty() const;
    void Display() const;
    ~Stack();
};


int main(void)
{
    try
    {
        Stack stack;
        
        for(int i = 1; i<= 5; i++)
        {
            stack.Push(10*i);
        }

        stack.Display();
        cout<<"Peek stack: "<<stack.Peek()<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(0);
}

Stack::~Stack(){
    if(top){
        while(NULL != top) { 
            Pop();
        } 
    }
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
        throw std::underflow_error("Stack Underflow on Pop()");
    }
    Node* temp = top;
    top = top->link;
    int popped = temp->data;
    delete temp;
    return popped;
}

int Stack::Peek() const
{
    if(IsEmpty()) {
        cout<<"\nStack Underflow"<<endl;
        return(-1);
    }
    return top->data;
}

bool Stack::IsEmpty() const
{
    return NULL == top;
}

void Stack::Display() const
{
    cout<<endl;
    if(IsEmpty())
    {
        throw std::underflow_error("Stack Underflow on Display()");
    }
    else
    {
        Node* temp = top;
        while(NULL != temp) 
        { 
            // print top element in stack 
            cout << temp->data <<" ->"; 
            temp = temp->link;
        } 
    }
    cout<<endl;
}
