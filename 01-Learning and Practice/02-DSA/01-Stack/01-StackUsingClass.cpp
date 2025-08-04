#include<iostream>

using namespace std;

class Stack
{
    int top;
    int *Data;
    int size;

    public:
    Stack(int size_s = 0):top(-1), size(size_s)
    {
        Data = new int[size];
        cout<<"Stack created !!"<<endl;
    }

    void Push(int);
    void Pop();
    int Peek() const;
    int GetSize() const;
    bool IsEmpty() const;
    bool IsFull() const;
    virtual ~Stack(){
        delete [] Data;
    }
};


int main(void)
{
    int stackSize;
    cout<<"Enter the size to create the stack: ";
    cin>>stackSize;

    Stack stack(stackSize);

    cout<<"Before Push Size of stack is: "<<stack.GetSize()<<endl;

    stack.Push(10);
    stack.Push(80);
    stack.Push(800);
    stack.Push(90);

    cout<<"After push Size of stack is: "<<stack.GetSize()<<endl;

    stack.Pop();

    cout<<"After pop Size of stack is: "<<stack.GetSize()<<endl;

    cout<<"Top element is: "<<stack.Peek();
    return 0;
}

int Stack::Peek() const
{
    if(IsEmpty())
    {
        cout<<"Stack is empty. Nothing to peek.\n"<<endl;
        return -1;
    }
    
    return Data[top];
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

    cout<<"Element poped: "<<Data[top--]<<endl;
}


int Stack::GetSize() const
{
    return(top + 1);
}


bool Stack::IsEmpty() const
{
    if(top < 0)
        return true;
    else
        return false;
}


bool Stack::IsFull() const
{
    if(top == (size - 1))
        return true;
    else
        return false;
}