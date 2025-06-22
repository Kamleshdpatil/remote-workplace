
// C++ program to Implement a stack
// using singly linked list

#include<iostream>
#include<stdlib.h>

using namespace std;

class Node
{
    public:
        int data;
        Node* link;
};

class Stack
{
    Node* top;
    public:
        Stack(){top = nullptr;}

        void push(int data)
        {
            Node* temp = new Node();
            if(!temp)
            {
                cout<<"\nStack overflow !"<<endl;
                exit(1);
            }

            // Initialize data into temp data field
            temp->data = data;
    
            // Put top pointer reference into temp link
            temp->link = top;
    
            // Make temp as top of Stack
            top = temp;
        }

        // Utility function to check if
        // the stack is empty or not
        bool isEmpty()
        {
            // If top is NULL it means that
            // there are no elements are in stack
            return top == NULL;
        }

        int peek()
        {
            // If stack is not empty , return the top element
            if(!isEmpty())
                return top->data;
            else
                exit(1);
        }

        void pop()
        {
            // Check for underflow
            if(top == nullptr)
            {
                cout<<"\nStack underflow !"<<endl;
                exit(1);
            }
            else
            {
                //Assign top to temp
                Node* temp = top;

                // Assign second node to top
                top = top->link;

                delete temp;
            }
        }

        //Display all elements
        void Display()
        {
            cout<<endl;
            // Check for underflow
            if(top == nullptr)
            {
                cout<<"\nStack underflow !"<<endl;
                exit(1);
            }
            else
            {
                //Assign top to temp
                Node* temp = top;

                while (temp != nullptr)
                {
                    cout<<temp->data;
                    temp = temp->link;
                    if(temp != nullptr)
                        cout<<" -> ";
                }
            }
            cout<<endl;
        }
};

int main(void)
{
   Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();

    st.pop();
    st.push(70);
    st.Display();

    cout<<"\nPeek: "<<st.peek();
   
    return(0);
}
