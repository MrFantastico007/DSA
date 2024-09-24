#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // constructor
    Node(int val)
    {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        // cout << temp->data << "->";
        temp = temp->next;
    }
    return len;
}

void InsertAtHead(Node *&tail, Node *&head, int val)
{
    Node *newhaed = new Node(val);
    if (head == NULL)
    {
        // Node *newhaed = new Node(val);
        head = newhaed;
        tail = newhaed;
    }
    else
    {
        // Node *newhaed = new Node(val);
        newhaed->next = head;
        head->prev = newhaed;
        head = newhaed;
    }
}

void InsertAtTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertAtPosition(Node *&head, Node *tail, int val, int pos)
{
    int curr = 1;
    if (pos == 1)
    {
        InsertAtHead(tail, head, val);
        return;
    }
    Node *temp1 = new Node(val);
    Node *temp2 = head;
    while (curr < pos - 1)
    {
        temp2 = temp2->next;
        curr++;
    }
    if (temp2->next == NULL)
    {
        InsertAtTail(tail, val);
        return;
    }

    temp1->next = temp2->next;
    temp2->next->prev = temp1;
    temp2->next = temp1;
    temp1->prev = temp2;
}
void DelFromPos(Node *&tail, Node *&head, int pos)
{
    int crr = 1;
    Node *temp = head;
    if (crr < pos - 1)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = temp->next->next;
    del->next->prev = temp;
    del->next = NULL;
    del->prev = NULL;
    free(del);
}

int main()
{
    // Node *N1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(tail, head, 9);
    // display(head);
    InsertAtHead(tail, head, 9);
    InsertAtHead(tail, head, 8);
    InsertAtHead(tail, head, 7);
    InsertAtTail(tail, 11);
    InsertAtPosition(head, tail, 69, 3);
    InsertAtPosition(head, tail, 70, 1);
    InsertAtPosition(head, tail, 71, 8);
    // DelFromPos(tail, head, 4);
    display(head);
    cout << getLength(head) << endl;
    cout << head->data << " " << tail->data;

    return 0;
}