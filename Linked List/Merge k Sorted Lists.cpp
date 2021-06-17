
// https://leetcode.com/problems/merge-k-sorted-lists/
// lc 23

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *merge(ListNode *a, ListNode *b)
    {
        if (a == nullptr)
        {
            cout << "##";
            return b;
        }

        if (b == nullptr)
        {
            return a;
        }

        ListNode *c;

        if (a->val <= b->val)
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

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        // priority queue ( min heap approach to getting minimum element from all the list).
        ListNode *head = new ListNode(0);
        ListNode *p = head;

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

        for (auto it : lists)
        {
            if (it)
                pq.push({it->val, it});
        }

        while (!pq.empty())
        {

            int val = pq.top().first;
            ListNode *node = pq.top().second;

            pq.pop();

            p->next = node;
            p = p->next;
            node = node->next;

            if (node)
            {
                pq.push({node->val, node});
            }
        }

        return head->next;

        // if (lists.size() == 0 or (lists.size() == 1 and lists[0] == nullptr))
        // {
        //     return nullptr;
        // }

        // if (lists.size() == 1 and lists[0] != nullptr)
        // {
        //     return lists[0];
        // }
        // ListNode *c = lists[0];

        // for (int i = 1; i < lists.size(); i++)
        // {

        //     c = merge(c, lists[i]);
        // }

        // return c;
    }
};