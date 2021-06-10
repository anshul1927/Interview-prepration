
// https://leetcode.com/problems/reorder-list/
// lc 143

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
    void reorderList(ListNode *A)
    {
        ListNode *slow = A, *fast = A->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow;
        ListNode *a = A;
        ListNode *b = mid->next;
        mid->next = nullptr;

        ListNode *prev = nullptr, *curr = b, *nxt;

        while (curr != nullptr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        b = prev;

        // cout<<b->val;
        // return b;

        while (b != nullptr)
        {
            ListNode *temp = a->next;
            a->next = b;
            ListNode *temp1 = b->next;
            b->next = temp;
            a = a->next->next;
            b = temp1;
        }
    }
};