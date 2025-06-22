#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
    int data;
    struct node *pNext;
}NODE, *PNODE, **PPNODE;

int LListSize(PNODE);
void LListDsiplay(PNODE);
void InsertAtFirst(PPNODE, int);
void InsertAtLast(PPNODE, int);
void DeleteLast(PPNODE);
void DeleteFirst(PPNODE);
void InsertAtPos(PPNODE, int, int);
void DeleteAtPos(PPNODE, int);
void ReverseList(PPNODE);
PNODE recurReverseList(PPNODE);

int main(void)
{
    PNODE head = (PNODE)malloc(sizeof(NODE));
    head->data = 20;
    head->pNext = NULL;

    //PNODE head;

    InsertAtLast(&head, 30);
    InsertAtLast(&head, 40);
    InsertAtLast(&head, 50);
    //InsertAtLast(&head, 60);
    InsertAtFirst(&head, 10);

    // int pos = 0;
    LListDsiplay(head);
    // cout<<"\nEnter positio: ";
    // cin>>pos;
    // cout<<endl;
    //InsertAtPos(&head, 70, pos);
    //DeleteAtPos(&head, pos);
    //DeleteFirst(&head);
    //DeleteLast(&head);

    //PNODE newHead = recurReverseList(&head);
    //LListDsiplay(newHead);
    ReverseList(&head);
    //DeleteFirst(&head);
    //DeleteLast(&head);

    LListDsiplay(head);

    return(0);
}

int LListSize(PNODE head_ref)
{
    int size = 0;
    while (head_ref != NULL)
    {
        size++;
        head_ref = head_ref->pNext;
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

void InsertAtFirst(PPNODE head_ref, int data)
{
    // make new node
    PNODE newNode = (PNODE)malloc(sizeof(NODE));

    // Fulfill the provided data and next is null.
    newNode->data = data;
    newNode->pNext = NULL;
    if(head_ref == NULL)
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
    PNODE newNode = (PNODE)malloc(sizeof(NODE));
    
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

void DeleteLast(PPNODE head_ref)
{
    if(*(head_ref) == NULL){return;}

    PNODE temp = *(head_ref);

    while (temp->pNext->pNext != NULL)
    {
        temp = temp->pNext;
    }
    temp->pNext = NULL;
}

void DeleteFirst(PPNODE head_ref)
{
    if(*(head_ref) == NULL){return;}

    PNODE temp = *(head_ref);

    if(temp->pNext == NULL)
    {
        free(*head_ref);
        *head_ref = NULL;
    }
    else
    {
        temp = temp->pNext;
        *(head_ref) = temp;
    }
}

void InsertAtPos(PPNODE head_ref, int data, int pos)
{
    int size = LListSize(*head_ref);
    if((pos < 1) || (pos > size + 1))
    {
        cout<<"\nInvalid Position"<<endl;
        return;
    }

    if(pos == 1)
    {
        InsertAtFirst(head_ref, data);
    }
    else if(pos == size+1)
    {
        InsertAtLast(head_ref, data);
    }
    else
    {
        // make new node
        PNODE newNode = (PNODE)malloc(sizeof(NODE));
        
        // Fulfill the provided data and next is null.
        newNode->data = data;
        newNode->pNext = NULL;

        int count = 0;
        PNODE temp = *(head_ref);

        while(temp->pNext != NULL)
        {
            count++;
            if(count == pos-1)
            {
                break;
            }
            temp = temp->pNext;
        }

        newNode->pNext = temp->pNext;
        temp->pNext = newNode;
    }
}

void DeleteAtPos(PPNODE head_ref, int pos)
{
    int size = LListSize(*head_ref);
    if((pos < 1) || (pos > size + 1))
    {
        cout<<"\nInvalid Position"<<endl;
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(head_ref);
    }
    else if(pos == size+1)
    {
        DeleteLast(head_ref);
    }
    else
    {
        int count = 0;
        PNODE temp = *(head_ref);

        while(temp->pNext != NULL)
        {
            count++;
            if(count == pos-1)
            {
                break;
            }
            temp = temp->pNext;
        }
        temp->pNext = temp->pNext->pNext;
    }
}

void ReverseList(PPNODE head_ref)
{
    //Initialize three pointers prev as NULL, curr as head, and next as NULL.
    PNODE prev = NULL;
    PNODE curr = *(head_ref);
    PNODE next = NULL;

    //Iterate through the linked list. In a loop, do the following
    while (curr != NULL)
    {
        //Before changing the next of curr, store the next node 
        next = curr->pNext;  // 1

        //Now update the next pointer of curr to the prev
        curr->pNext = prev; // 2

        //Update prev as curr and curr as next
        prev = curr; // 3

        // Make next is current
        curr = next; // 4
    }

    // Make prev to head which was last node
    *head_ref = prev;
}

PNODE recurReverseList(PPNODE head_ref)
{
    PNODE head = *(head_ref);
    if((head == NULL) || (head->pNext == NULL))
    {
        return head;
    }

    PNODE newHead = recurReverseList(&(head->pNext));
    PNODE headNext = head->pNext;
    headNext->pNext = head;
    head->pNext = NULL;

    return(newHead);

}
