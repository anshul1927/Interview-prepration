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

    void reverse(int k)
    {
        head = k_reverse(k, head);
    }

    Node *k_reverse(int k, Node *head)
    {
        if (head == NULL)
        {
            return nullptr;
        }
        Node *prev = NULL, *curr = head, *nxt = head;
        int t = k;
        while (curr != nullptr && t--)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        cout << prev->val << endl;
        if (nxt != nullptr)
            head->next = k_reverse(k, nxt);
        return prev;
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
    ls.insertAtHead(9);
    ls.insertAtHead(8);
    ls.insertAtHead(7);
    ls.insertAtHead(6);
    ls.insertAtHead(5);
    ls.insertAtHead(4);
    ls.insertAtHead(3);
    ls.insertAtHead(2);
    ls.insertAtHead(1);
    ls.insertAtHead(0);

    ls.printList();
    int k;
    cin >> k;
    ls.reverse(k);
    ls.printList();

    return 0;
}