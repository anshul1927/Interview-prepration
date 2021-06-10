
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// lc 1721

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {

        if (head == NULL)
        {
            return NULL;
        }

        ListNode *p = head;
        for (int i = 0; i < k - 1; i++)
        {
            p = p->next;
        }

        ListNode *first = p;

        ListNode *q = head;

        while (p->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        swap(q->val, first->val);

        return head;
    }
};