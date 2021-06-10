#include <bits/stdc++.h>
#include "create_linked_list.cpp"
using namespace std;

int main()
{

    LinkedList *ls = new LinkedList();

    ls->insertAtHead(10);
    ls->insertAtHead(9);
    ls->insertAtHead(8);
    ls->insertAtHead(7);
    ls->insertAtHead(6);
    ls->insertAtHead(5);
    ls->insertAtHead(4);
    ls->insertAtHead(3);
    ls->insertAtHead(2);
    ls->insertAtHead(1);

    ls->printList();

    int k;
    cin >> k;

    Node *slow, *fast;
    slow = ls->getHead();
    fast = slow;

    while (k--)
    {
        fast = fast->next;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    cout << slow->val;
    slow->next = slow->next->next;
    cout << endl
         << slow->next->val;
    return 0;
}