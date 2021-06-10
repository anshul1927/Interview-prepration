#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    int len = 0;
    Node *head = NULL;
    Node *getHead()
    {
        return head;
    }
    void insertAtHead(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
            len++;
            return;
        }

        Node *n = new Node(data);
        n->next = head;
        head = n;
        len++;
        return;
    }

    void printList()
    {
        if (head == NULL)
        {
            return;
        }
        Node *p = head;

        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
        return;
    }
};

Node *merge(Node *a, Node *b)
{
    if (a == nullptr)
    {
        return b;
    }
    if (b == nullptr)
    {
        return a;
    }
    Node *c;

    if (a->val < b->val)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }

    return c;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *p = head;

    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return;
}

int main()
{
    LinkedList ls;
    ls.insertAtHead(10);
    ls.insertAtHead(7);
    ls.insertAtHead(5);
    ls.insertAtHead(1);

    LinkedList ls1;
    ls1.insertAtHead(6);
    ls1.insertAtHead(3);
    ls1.insertAtHead(2);

    ls.printList();
    ls1.printList();

    Node *a = ls.getHead(), *b = ls1.getHead();

    cout << a->val;
    cout << b->val;
    Node *c = merge(a, b);
    cout << c->val;
    cout << endl;
    printList(c);
    return 0;
}