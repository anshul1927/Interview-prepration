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

    Node *reverse_recusive(Node *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        Node *sHead = reverse_recusive(head->next);
        head->next->next = head;
        head->next = NULL;
        return sHead;
    }

    void iterative_recursive()
    {
        Node *prev = NULL, *curr = head, *nxt = head;

        while (curr != nullptr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }
    void reverse()
    {
        head = reverse_recusive(head);
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

int main()
{
    LinkedList ls;
    ls.insertAtHead(4);
    ls.insertAtHead(3);
    ls.insertAtHead(2);
    ls.insertAtHead(1);
    ls.insertAtHead(0);

    ls.printList();
    ls.reverse();
    ls.printList();
    ls.iterative_recursive();
    ls.printList();
    return 0;
}