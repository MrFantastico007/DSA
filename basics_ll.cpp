#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void InsertAtTail(Node *&head, int val)
{
    Node *temp = head;
    Node *t = new Node(val);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = t;
    t->next = NULL;
}

void InsertAtPosition(Node *&head, int pos, int val)
{
    if (pos == 1)
        InsertAtHead(head, val);
    else
    {

        Node *temp = new Node(val);
        Node *t = head;
        int i = 1;
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        // while (i < pos - 1)
        // {
        //     t = t->next;
        //     i++;
        // }
        temp->next = t->next;
        t->next = temp;
    }
}
void DeleteFromPositon(Node *head, int pos)
{
    Node *temp = head;
    Node *t;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    t = temp->next;
    temp->next = temp->next->next;
    free(t);
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 11);
    InsertAtTail(head, 15);
    InsertAtHead(head, 50);
    // InsertAtPosition(head, 3, 9);
    InsertAtPosition(head, 1, 69);
    DeleteFromPositon(head, 2);
    display(head);
    // cout << head->data;
    return 0;
}