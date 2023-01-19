#include<bits/stdc++.h>
using namespace std;

// create Node class
class Node
{
public:
    Node* prev;
    int data;
    Node* next;
};

// create DoublyLinkedList class
class DoublyLinkedList
{
public:
    // create head node
    Node* head;
    int sz;
    Node* tail;
    // create a DoublyLinkedList constructor to initialize head , prev and next value
    DoublyLinkedList()
    {
        head=NULL;
        sz=0;
        tail=NULL;
    };
    // create a CreateNewNode function
    Node* CreateNewNode(int value)
    {
        // allocate memory for newNode;
        Node* newNode = new Node();
        newNode->data=value;
        newNode->prev=NULL;
        newNode->next=NULL;
        return newNode;
    };
    void InsertAtHead(int value)
    {
        // create a newNode
        Node* newNode = CreateNewNode(value);
        // track the tail node;
        if(sz==0)
        {
            tail=newNode;
        }
        // increase the size;
        sz++;
        // check if the head is null or not
        if(head==NULL)
        {
            head=newNode;
            return;
        };
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    };
    void InsertAtAnyIndex(int index, int value)
    {
        if(index==0)
        {
            InsertAtHead(value);
            return;
        };
        Node* a=head;
        int c_idx=0;
        while(a!=NULL)
        {
            if(c_idx==index)
                break;
            c_idx++;
            a=a->next;
        };
        cout << "c_idx: "<< c_idx << " " << a->data << "\n";
        Node* prevNode=a->prev;
        Node* nextNode=a;
        // create newNode
        Node* newNode=CreateNewNode(value);
        newNode->prev=prevNode;
        newNode->next=a;
        prevNode->next=newNode;
        nextNode->prev=newNode;
        // increase the size of the list
        sz++;
    }
    void Traverse()
    {
        Node* a=head;
        while(a!=NULL)
        {
            cout << a->data << " ";
            a=a->next;
        };
        cout << "\n";
    };
    void ReverseTraverse()
    {
        Node* a=tail;
        while(a!=NULL)
        {
            cout << a->data << " ";
            a=a->prev;
        };
        cout << "\n";
    };
    void DeleteAtHead()
    {
        Node* a=head;
        Node* b=a->next;
        b->prev=NULL;
        head=b;
        delete a;
        // decrease the size
        sz--;
    };
    void DeleteAtTali()
    {
        Node* a=tail;
        Node* b=tail->prev;
        b->next=NULL;
        tail=b;
        delete a;
        // decrease the size
        sz--;
    };
    void DeleteAtAnyIndex(int index)
    {
        if(index==0)
        {
            DeleteAtHead();
            return;
        }else if(index==sz-1)
        {
            DeleteAtTali();
            return;
        };
        Node* a=head;
        int c_idx=0;
        while(a!=NULL)
        {
            if(c_idx==index)
                break;
            a=a->next;
            c_idx++;
        };
        Node* prevNode=a->prev;
        Node* nextNode=a->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        delete a;  
        // decrease the size
        sz--;
    }
    int GetSize()
    {
        return sz;
    };
};

int main()
{
    DoublyLinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.InsertAtHead(40);
    l.InsertAtHead(50);
    l.Traverse();
    cout << l.GetSize() << "\n";
    l.ReverseTraverse();
    cout << "end";
    l.InsertAtAnyIndex(2,117);
    l.Traverse();
    cout << l.GetSize() << "\n";
    l.DeleteAtHead();
    l.Traverse();
    cout << l.GetSize() << "\n";
    l.DeleteAtTali();
    l.Traverse();
    cout << l.GetSize() <<"\n";
    l.DeleteAtAnyIndex(1);
    l.Traverse();
    cout << l.GetSize();
    return 0;
}
