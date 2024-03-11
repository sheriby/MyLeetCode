#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        for (int i = 0; i < n; i++) p = p->next;
        if (!p->next) return head->next;
        p = p->next;
        while (p) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};