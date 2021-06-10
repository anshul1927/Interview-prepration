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
    void insertAtLast(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
            len++;
        }

        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        Node *n = new Node(data);
        p->next = n;
        len++;
    }

    void insertAtKthPosition(int data, int k)
    {

        if (k < 0 || k > len)
        {
            return;
        }
        if (k == 0)
        {
            insertAtHead(data);
        }
        else if (k == len)
        {
            insertAtLast(data);
        }
        else
        {
            Node *curr = head;
            while (k > 1)
            {
                k--;
                curr = curr->next;
            }

            Node *n = new Node(data);
            n->next = curr->next;
            curr->next = n;
            len++;
        }
    }

    bool search(int k)
    {
        Node *p = head;

        while (p != NULL)
        {
            if (p->val == k)
            {
                return true;
            }
            p = p->next;
        }

        return false;
    }

    void deleteatfirstnode()
    {
        head = head->next;
        len--;
    }

    void deleteatLast()
    {
        Node *p = head;

        while (p->next->next != NULL)
        {
            p = p->next;
        }

        p->next = NULL;
        len--;
    }

    void deleteafterKthNode(int k)
    {
        if (k < 0 || k >= len)
        {
            return;
        }
        if (k == 0)
        {
            deleteatfirstnode();
        }

        if (k == len - 1)
        {
            deleteatLast();
        }
        Node *p = head;
        k = k - 1;
        while (k--)
        {
            p = p->next;
        }
        p->next = p->next->next;
        len--;
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
