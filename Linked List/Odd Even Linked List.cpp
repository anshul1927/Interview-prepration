
// https://leetcode.com/problems/odd-even-linked-list/
// lc 328

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
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *odd = head, *even = head->next, *evenHead = even;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
        //         int len = 0;

        //     ListNode *t = A;

        //     while(t!=nullptr){
        //         t = t->next;
        //         len++;
        //     }

        //     if(len<=2){
        //         return A;
        //     }

        //     ListNode *a = A,* a1 = a, *b = A->next, *b1 = b;

        //     if(len%2==0){

        //         while(a1->next!=nullptr && b1->next!=nullptr){
        //             a1->next = b1->next;
        //             b1->next = a1->next->next;
        //             a1 = a1->next;
        //             b1 = b1->next;
        //         }
        //         a1->next = nullptr;
        //     }else{
        //          while(a1->next!=nullptr && b1->next!=nullptr){
        //             a1->next = b1->next;

        //             b1->next = a1->next->next;
        //             a1 = a1->next;
        //             if(b1->next == nullptr){
        //                 break;
        //             }
        //             b1 = b1->next;
        //         }
        //     }

        //         ListNode *k = a;
        //         while(k->next!=NULL){
        //             k = k->next;
        //         }

        //         k->next = b;

        //         return a;
    }
};