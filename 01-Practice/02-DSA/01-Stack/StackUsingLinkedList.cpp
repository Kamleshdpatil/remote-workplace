#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* pNext;
} Stack;

Stack* CreateStack(int);
void Push(Stack**, int);
int Pop(Stack**);
int Peek(Stack*);
bool IsEmpty(Stack*);

int main(void)
{
    Stack* root = NULL;

    Push(&root, 10);
    Push(&root, 20); 
    Push(&root, 30); 
  
    cout << Pop(&root) << " popped from stack\n"; 
  
    cout << "Top element is " << Peek(root) << endl; 
      
    cout <<"Elements present in stack : ";

     while(!IsEmpty(root)) 
    { 
        // print top element in stack 
        cout << Peek(root) <<" "; 
        // remove top element in stack 
        //Pop(&root); 
        root = root->pNext;
    } 

    return(0);
}

Stack* CreateStack(int data)
{
    Stack* node = (Stack*)malloc(sizeof(Stack));
    node->data = data;
    node->pNext = NULL;

    return(node);
}

void Push(Stack** stack, int data)
{
    Stack* node = CreateStack(data);
    if(IsEmpty(*stack))
        *stack = node;
    else
    {
        node->pNext = *stack;
        *stack = node;
    }
    cout << data << " pushed to stack\n"; 
}

int Pop(Stack** stack)
{
    if(IsEmpty(*stack))
        return INT_MIN;
    Stack* temp = *stack;
    *stack = (*stack)->pNext;
    int popped = temp->data;
    free(temp);
    return(popped);
}

int Peek(Stack* stack)
{
    if(IsEmpty(stack))
        return INT_MIN;
    return stack->data;
}

bool IsEmpty(Stack* stack)
{
    return !stack;
}
