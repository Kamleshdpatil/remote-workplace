#include<iostream>

using namespace std;

typedef class Node{
    public:
    int data;
    Node* pNext;

    Node(int x = 0):data(x){}
    Node(const Node& newNode){cout<<"\nCopy constructor called!!"<<endl;}
    private:
    ~Node(){}
    
}NODE, *PNODE, **PPNODE;

PNODE getIntersectNode(PNODE, PNODE);
void InsertAtFirst(PPNODE, int);
void InsertAtLast(PPNODE, int);
int LListSize(PNODE);
void LListDsiplay(PNODE);

int main(void)
{
    PNODE newNode = new Node(70);
    newNode->data = 15;
    newNode->pNext = NULL;
    PNODE onj = new Node(*newNode);
    //onj->data = 15;
    //onj = newNode;

    InsertAtFirst(&newNode, 11);
    InsertAtFirst(&newNode, 12);
    InsertAtFirst(&newNode, 13);

    LListDsiplay(newNode);
    PNODE ret = getIntersectNode(newNode, onj);
    if(ret)
        cout<<ret->data<<endl;
    else
        cout<<"NULL";
    return(0);
}

PNODE getIntesectionNode(PNODE head1, PNODE head2)
{
    while (head2) {
        PNODE temp = head1;
        while (temp) {
            // if both Nodes are same
            if (temp == head2)
                return head2;
            temp = temp->pNext;
        }
        head2 = head2->pNext;
    }
    // intersection is not present between the lists
    return NULL;
}

void InsertAtFirst(PPNODE head_ref, int data)
{
    // make new node
    PNODE newNode = new NODE();

    // Fulfill the provided data and next is null.
    newNode->data = data;
    newNode->pNext = NULL;
    if(*(head_ref) == NULL)
    {
        *(head_ref) = newNode;
    }
    else
    {
        newNode->pNext = *(head_ref);
        *(head_ref) = newNode;
    }
}

void InsertAtLast(PPNODE head_ref, int data)
{
    // make new node
    PNODE newNode = new NODE();
    
    // Fulfill the provided data and next is null.
    newNode->data = data;
    newNode->pNext = NULL;

    // Give size of present list
    int size = LListSize(*head_ref);
    if(size < 1)
    {
        *(head_ref) = newNode;
    }
    else
    {
        PNODE temp = *(head_ref);

        while (temp->pNext != NULL)
        {
            temp = temp->pNext;
        }

        temp->pNext = newNode;
    }
}

int LListSize(PNODE head_ref)
{
    int size = 0;
    PNODE temp = head_ref;
    while (temp != NULL)
    {
        size++;
        temp = temp->pNext;
    }
    return(size);
}

void LListDsiplay(PNODE head_ref)
{
    cout<<endl;
    if(head_ref == NULL)
    {
        cout<<"\nList is Empty !!"<<endl;
        return;
    }
    else
    {
        while (head_ref != NULL)
        {
            cout<<"|"<<head_ref->data<<"|->"<<" ";
            head_ref = head_ref->pNext;
        }
    }
    cout<<endl;
}
