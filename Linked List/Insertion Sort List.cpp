
// https://leetcode.com/problems/insertion-sort-list/
// lc 147

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
    ListNode *insertionSortList(ListNode *A)
    {
        ListNode *start = new ListNode(0);
        ListNode *head = A;
        start->next = head;
        ListNode *prev = start;
        ListNode *i = head;

        while (i != nullptr)
        {

            if (i->next && (i->val > i->next->val))
            {
                while (prev->next && (prev->next->val < i->next->val))
                    prev = prev->next;

                ListNode *temp = prev->next;
                prev->next = i->next;
                i->next = i->next->next;
                prev->next->next = temp;
                prev = start;
            }
            else
            {
                i = i->next;
            }
        }

        return start->next;
    }
};