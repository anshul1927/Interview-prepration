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

    a->next->next->next->next->next->next->next->next = a->next->next->next;
    cout << endl;

    Node *slow = a;
    Node *fast = a;

    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }

    if (slow == fast)
    {
        cout << "cycle present";
    }
    else
    {
        cout << "cycle not present";
    }

    // break the cycle

    slow = a; // for getting node where cycle begins.
    Node *b;  // for breaking cycle
    while (slow != fast)
    {
        slow = slow->next;
        b = fast;
        fast = fast->next;
    }

    cout << endl;
    cout << slow->val;
    cout << fast->val;
    cout << b->val;
    cout << endl;

    b->next = nullptr;
    ls.printList();
    return 0;
}