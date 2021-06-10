
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// lc 19

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *first = head, *second = head;

        for (int i = 0; i < n; i++)
        {
            second = second->next;
        }

        ListNode *prev;
        if (!second)
            return head->next;

        while (second->next != NULL)
        {

            first = first->next;
            second = second->next;
        }

        first->next = first->next->next;
        return head;
    }
};