#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val > list2->val) return mergeTwoLists(list2, list1);
        ListNode *head = list1, *p = list1;
        list1 = list1->next;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        if (list1)
            p->next = list1;
        else if (list2)
            p->next = list2;
        else
            p->next = nullptr;
        return head;
    }
};