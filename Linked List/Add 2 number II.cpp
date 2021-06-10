
// https://leetcode.com/problems/add-two-numbers-ii/
// lc 445

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
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL;

        while (curr != nullptr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *A = reverse(l1);

        ListNode *B = reverse(l2);

        if (A == nullptr)
        {
            return B;
        }
        else if (B == nullptr)
        {
            return A;
        }
        else
        {
            ListNode *temp = NULL, *dummy = NULL;
            int carry = 0;
            int rem = 0;
            while (A != nullptr and B != nullptr)
            {
                rem = (A->val + B->val + carry) % 10;
                carry = (A->val + B->val + carry) / 10;
                ListNode *a = new ListNode(rem);
                if (temp == nullptr)
                {
                    temp = a;
                    dummy = temp;
                }
                else
                {
                    temp->next = a;
                    temp = temp->next;
                }
                A = A->next;
                B = B->next;
            }

            // cout<<"##"<<endl;
            while (A != NULL)
            {
                rem = (A->val + carry) % 10;
                carry = (A->val + carry) / 10;

                temp->next = new ListNode(rem);

                temp = temp->next;
                A = A->next;
            }

            // cout<<"##"<<endl;
            while (B != NULL)
            {
                rem = (B->val + carry) % 10;
                carry = (B->val + carry) / 10;

                temp->next = new ListNode(rem);

                temp = temp->next;
                B = B->next;
            }

            // cout<<"##"<<endl;

            if (carry != 0)
            {
                temp->next = new ListNode(carry);
            }
            // cout<<temp->val;
            // cout<<"##"<<endl;
            // cout<<dummy->val;
            return reverse(dummy);
        }
    }
};