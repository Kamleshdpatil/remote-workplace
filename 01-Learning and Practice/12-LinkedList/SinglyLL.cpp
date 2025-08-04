#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

class ListNode
{
    public:
        ListNode* next;
        int val;
    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int data) : val(data), next(NULL) {}

    ListNode(int data, ListNode* nextPtr): val(data), next(nextPtr) {}
};

ListNode* createLinkedListUsingVector(ListNode* head, vector<int>& nums)
{
    for(int i = nums.size()-1; i >= 0; --i)
    {
        ListNode* newNode = new ListNode(nums[i], head);
        head = newNode;
    }
    return head;
}

int getSizeOfLinkedList(ListNode* head)
{
    int size = 0;
    if(head != NULL){
        ListNode* temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }
    }
    return size;
}

void Display(ListNode* head)
{
    if(head != NULL){
        cout<<endl<<"List: ";
        ListNode* temp = head;
        while (temp)
        {
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<endl<<endl;
    }
}

void DisplayCyclicLL(ListNode* head)
{
    int counter = 15;
    if(head != NULL){
        cout<<endl<<"List: ";
        ListNode* temp = head;
        while (counter--)
        {
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<endl<<endl;
    }
}

ListNode* insertAtHead(ListNode* head, int data)
{
    if(head == NULL){
        ListNode* newNode = new ListNode(data);
        head = newNode;
    }else{
        ListNode* newNode = new ListNode(data, head);
        head = newNode;
    }
    return head;
}

ListNode* insertAtTail(ListNode* head, int data)
{
    if(head == NULL){
        ListNode* newNode = new ListNode(data);
        head = newNode;
    }else{
        ListNode* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        ListNode* newNode = new ListNode(data);
        temp->next = newNode;
    }
    return head;
}

bool isCyclicLinkedListFound(ListNode* head)
{
    if(head != NULL && head->next != NULL){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return false;
}

void createCycleOfList(ListNode* head)
{
    ListNode* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    DisplayCyclicLL(head);
}

void createInterSection(ListNode* headA, ListNode* headB)
{
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    int counter = 3;
    while (counter--)
    {
        // cout<<"tempA->val: "<<tempA->val<<endl;
        tempA = tempA->next;
    }
    while (tempB->next != NULL)
    {
        // cout<<"tempB->val: "<<tempB->val<<endl;
        tempB = tempB->next;
    }
    tempB->next = tempA;
}

bool checkIntersectionParellaly(ListNode* headA, ListNode* headB, int place)
{
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    for(int i = 0; i < place; i++)
    {
        tempA = tempA->next;
    }

    while (tempA && tempB)
    {
        if(tempA == tempB)
            return true;
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return false;
}

bool isInterSectionLinkedListFound(ListNode* headA, ListNode* headB)
{
    int sizeA = getSizeOfLinkedList(headA);
    int sizeB = getSizeOfLinkedList(headB);
    if(sizeA > sizeB)
        return checkIntersectionParellaly(headA, headB, sizeA-sizeB);
    else
        return checkIntersectionParellaly(headB, headA, sizeB-sizeA);
}

ListNode* reverseLinkedList(ListNode* head)
{
    if(head == NULL){return NULL;}

    ListNode* prev = NULL;
    ListNode* curent = head;
    ListNode* next = head->next;
    while (curent != NULL)
    {
        next = curent->next;
        curent->next = prev;
        prev = curent;
        curent = next;
    }
    
    return prev;
}

ListNode* sortLinkedList(ListNode* head, bool isAscending)
{
    if(head == NULL){return NULL;}
    vector<int> vecInt;
    
    ListNode* temp = head;
    while (temp != NULL)
    {
        vecInt.push_back(temp->val);
        temp = temp->next;
    }
    if(isAscending)
        sort(vecInt.begin(), vecInt.end());
    else
        sort(vecInt.begin(), vecInt.end(), greater<int>());

    temp = head;
    for(auto it : vecInt)
    {
        temp->val = it;
        temp = temp->next;
    }

    return head;
}

ListNode* getMiddleNodeOfLinkedList(ListNode* head)
{
    if(head != NULL && head->next != NULL){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    return NULL;
}

int main()
{
    ListNode* head = NULL;
    vector<int> vecInt = {60, 22, 50, 40, 30, 15, 75, 55, 77};
    head = createLinkedListUsingVector(head, vecInt);
    Display(head);
    
    // head = insertAtHead(head, 100);
    // Display(head);

    // head = insertAtTail(head, 100);
    // Display(head);

    // createCycleOfList(head);
    // bool bIsLoop = isCyclicLinkedListFound(head);
    // if(bIsLoop)
    //     cout<<"Loop found in this list !!"<<endl;
    // else
    //     cout<<"Loop Not found !!"<<endl;
    
    // vector<int> vecIntB = {100, 125};
    // ListNode* headB = NULL;
    // headB = createLinkedListUsingVector(headB, vecIntB);
    // // createInterSection(head, headB);
    // // cout<<"List A"<<endl;
    // // Display(head);
    // // cout<<"List B"<<endl;
    // // Display(headB);

    // bool bIsInterSection = isInterSectionLinkedListFound(head, headB);
    // if(bIsInterSection)
    //     cout<<"Intersection found in this list !!"<<endl;
    // else
    //     cout<<"Intersection Not found !!"<<endl;

    // head = reverseLinkedList(head);
    // cout<<"After Reverse: "<<endl;
    // Display(head);

    // head = sortLinkedList(head, false);
    // cout<<"After Sorting: "<<endl;
    // Display(head);
    
    ListNode* middleNode = getMiddleNodeOfLinkedList(head);
    cout<<"middleNode: "<<middleNode->val<<endl;
    // Display(head);

    return(0);
}
