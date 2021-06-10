
// https://leetcode.com/problems/reverse-nodes-in-k-group/
// lc 25

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL)
        {
            return nullptr;
        }

        int len = 0;
        ListNode *m = head;

        while (m != nullptr)
        {
            len++;
            m = m->next;
        }
        if (len - k < 0)
        {
            return head;
        }

        ListNode *prev = NULL, *curr = head, *nxt = head;
        int t = k;

        while (curr != nullptr && t--)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if (nxt != nullptr)
            head->next = reverseKGroup(nxt, k);
        return prev;
    }
};