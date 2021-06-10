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

Node *midPoint(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *mergeSort(Node *head)
{
    //base case;
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    Node *mid = midPoint(head);
    Node *a = head;
    Node *b = mid->next;
    mid->next = nullptr;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a, b);
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
    ls.insertAtHead(4);
    ls.insertAtHead(3);
    ls.insertAtHead(9);
    ls.insertAtHead(2);
    ls.insertAtHead(0);
    ls.insertAtHead(8);
    ls.insertAtHead(12);
    ls.insertAtHead(11);

    ls.printList();

    Node *a = ls.getHead();

    cout << a->val;
    a = mergeSort(a);
    cout << a->val;
    cout << endl;
    printList(a);
    return 0;
}