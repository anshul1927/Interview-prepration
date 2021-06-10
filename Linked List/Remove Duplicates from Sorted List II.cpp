
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// lc 82

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
    ListNode *deleteDuplicates(ListNode *A)
    {
        if (A == nullptr or A->next == nullptr)
        {
            return A;
        }
        ListNode *start, *tail;
        start = tail = nullptr;

        for (ListNode *it = A; it != nullptr; it = it->next)
        {

            if (it->next != nullptr && it->val == it->next->val)
            {

                while (it->next != nullptr && it->val == it->next->val)
                {
                    it = it->next;
                }
                continue;
            }

            if (start == nullptr)
            {
                start = tail = it;
            }
            else
            {
                tail->next = it;
                tail = it;
            }
        }

        if (tail != nullptr)
            tail->next = nullptr;
        return start;
    }
};