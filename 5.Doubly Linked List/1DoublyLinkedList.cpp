#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next, *prev;
    node(int data)
    {
        item = data;
        next = NULL;
        prev = NULL;
    }
};
class DLL
{
private:
    node *start;

public:
    DLL();
    void insertAtStart(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(int, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~DLL();
};
DLL::DLL()
{
    start = NULL;
}
void DLL::insertAtStart(int data)
{
    node *n = new node(data);
    n->next = start;
    if (start)
        start->prev = n;
    start = n;
}
void DLL::insertAtLast(int data)
{
    node *n = new node(data);
    if (start == NULL)
    {
        start = n;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        n->prev = temp;
        temp->next = n;
    }
}
node *DLL::search(int data)
{
    node *temp = start;
    while (temp)
    {
        if (temp->item == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void DLL::insertAfter(int data, int d)
{
    node *n = new node(d);
    node *temp = start;
    while (temp)
    {
        if (temp->item == data)
            break;
        temp = temp->next;
    }
    if (temp)
    {
        n->next = temp->next;
        n->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = n;
        temp->next = n;
    }
}
void DLL::deleteFirst()
{
    node *temp;
    if (start != NULL)
    {
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            temp = start;
            start->next->prev = NULL;
            start = start->next;
            delete temp;
        }
    }
}
void DLL::deleteLast()
{
    node *temp;
    if (start != NULL)
    {
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
    }
}
void DLL::deleteNode(int data)
{
    node *temp = start;
    while (temp)
    {
        if (temp->item == data)
        {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            if (temp->prev == NULL)
                start = temp->next;
            delete temp;
            break;
        }
        temp = temp->next;
    }
}
DLL::~DLL()
{
    while(start)
      deleteFirst();
}