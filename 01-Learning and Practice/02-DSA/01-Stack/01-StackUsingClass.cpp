#include<iostream>
#include<cstdlib>

using namespace std;
#define MAX 20 

class Stack
{
    int top;

    public:
    int Data[MAX];
    Stack():top(-1)
    {
        cout<<"Stack created !!"<<endl;
    }

    void Push(int);
    void Pop();
    int GetSize();
    bool IsEmpty();
    bool IsFull();
};


int main(void)
{
    Stack stack;

    cout<<"Before Push Size of stack is: "<<stack.GetSize()<<endl;

    stack.Push(10);
    stack.Push(80);
    stack.Push(800);
    stack.Push(90);

    cout<<"After push Size of stack is: "<<stack.GetSize()<<endl;

    stack.Pop();

    cout<<"After pop Size of stack is: "<<stack.GetSize()<<endl;
    return(0);
}

void Stack::Push(int element)
{
    if(IsFull())
    {
        cout<<"Stack overflow!!\n"<<endl;
        return;
    }
    Data[++top] = element;
    cout<<"\nElement pushed: "<<Data[top]<<endl;
}


void Stack::Pop()
{
    if(IsEmpty())
    {
        cout<<"\nStack underflow!!"<<endl;
        return;
    }

    cout<<"Element poped: "<<Data[top]<<endl;
    Data[top] = Data[top--];

    return;
}


int Stack::GetSize()
{
    return(top + 1);
}


bool Stack::IsEmpty()
{
    if(top < 0)
        return true;
    else
        return false;
}


bool Stack::IsFull()
{
    if(top == MAX -1)
        return true;
    else
        return false;
}