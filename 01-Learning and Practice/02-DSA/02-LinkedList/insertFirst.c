#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void AddAtFirst(struct Node** head_ref, int data)
{
    // 1. Make new node and allocate the memory
    struct Node* newn = (struct Node*)malloc(sizeof(struct Node));

    //2. Assign data to the newly created node's data
    newn->data = data;

    //3. store head's address in newly created node's next.
    newn->next = (*head_ref);

    //4. Move the point to the head towards newly created node.(making head)
    (*head_ref) = newn;
}

void InsertAtLast(struct Node** head_ref, int data)
{
    //1. Make a new node and allocate the memory.
    struct Node* newn = (struct Node*)malloc(sizeof(struct Node));

    //2. Insert data to new node.
    newn->data = data;

    //3. Store head's address to temp;
    struct Node* temp = (*head_ref);

    //4. Check if List is empty else Traverse the all node till find the last node.
    if((*head_ref) == NULL)
    {
        (*head_ref) = newn;
    }
    else
    {
        while (temp->next != NULL) //Last node's next is empty.
        {
            temp = temp->next;
        }
    }
    
    //4. Store the new node's address in last node's next(which was empty previously);
    temp->next = newn;
    newn->next = NULL;
}

void AddAtPos(struct Node** head, int data, int pos)
{
    int i = 0;  // it will hold count of iteration for each node.

    //1. Make a new node and allocate the memory.
    struct Node* newn = (struct Node*)malloc(sizeof(struct Node));

    //2. Insert data to new node.
    newn->data = data;

    //3. Store head's address to temp;
    struct Node* temp = (*head);

    //4. Traverse the all node till find the specified position of node.
    while (temp->next != NULL)
    {
        i++;
        if(i == pos)
        {
            break;
        }
        temp = temp->next;
    }
    
    //5. store address of next node of specified position
    newn->next = temp->next;

    //6. store address of newly added node at specified location.
    temp->next = newn;
}

void Display(struct Node* head)
{
    while (head != NULL)
    {
        printf("|%d| ", head->data);
        head = head->next;
    }
}

int main(void)
{
    struct Node *head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 200;
    head->next = NULL;

    AddAtFirst(&head, 100);
    InsertAtLast(&head, 300);
    InsertAtLast(&head, 400);
    InsertAtLast(&head, 600);
    InsertAtLast(&head, 700);
    InsertAtLast(&head, 800);

    AddAtPos(&head, 500, 4);
    AddAtPos(&head, 900, 9);
    InsertAtLast(&head, 1000);
    AddAtFirst(&head, 00);

    Display(head);
}
