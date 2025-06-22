#include<iostream>
#include<cstdlib>

using namespace std;

struct Stack
{
    int capacity;
    int top;
    int* data;
};

Stack* CreateStack(int);
void Push(Stack*, int);
int Pop(Stack*);
int GetSize(Stack*);
bool IsEmpty(Stack*);
bool IsFull(Stack*);
void DeleteStack(Stack*);

int main(void)
{
    int size = 0;
    cout<<"Enter the size of stack: ";
    cin>> size;

    Stack* myStack = CreateStack(size);
    if(myStack == NULL)
    {
        cout<<"CreateStack() failed"<<endl;
        return(-1);
    }

    cout<<"\nStack capacity: "<<myStack->capacity<<endl;

    Push(myStack, 10);
    Push(myStack, 40);
    Push(myStack, 70);
    Push(myStack, 100);
    Push(myStack, 90);

    cout<<"Stack size: "<<GetSize(myStack)<<endl;

    cout<<"Pop element: "<<Pop(myStack)<<endl;

    cout<<"Stack size: "<<GetSize(myStack)<<endl;

    DeleteStack(myStack);
    
    return(0);
}


Stack* CreateStack(int size)
{
    Stack* stack = (Stack*)malloc(size * sizeof(int));
    stack->capacity = size;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));

    return(stack);
}

void DeleteStack(Stack* stack)
{
    if(stack == NULL)
        return;
    free(stack);
    stack = NULL;
}


void Push(Stack* stack, int element)
{
    if(IsFull(stack))
    {
        cout<<"Stack overflow value "<<element<<" is ignored !!!"<<endl;
        return;
    }
    else
        stack->data[++stack->top] = element;
}


int Pop(Stack* stack)
{
    if(IsEmpty(stack))
    {
        cout<<"Stack underflow!!!"<<endl;
        return 0;
    }
    else
        return stack->data[stack->top--];
}


int GetSize(Stack* stack)
{
    if(IsEmpty(stack))
        return stack->top;
    else
        return stack->top + 1;
}


bool IsEmpty(Stack* stack)
{
    if(stack->top < 0)
        return true;
    else
        return false;
}


bool IsFull(Stack* stack)
{
    if(stack->top == stack->capacity -1)
        return true;
    else
        return false;
}
