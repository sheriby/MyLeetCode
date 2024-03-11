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

typedef ListNode* List;
class Solution {
   public:
    // 1->2->3->4
    // 2->1->4->3
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        List cur = head, next = head->next, prev = nullptr;
        head = head->next;
        while (cur && next) {
            if (prev) prev->next = next;
            List tmp = next->next;
            next->next = cur;
            cur->next = tmp;
            prev = cur;
            cur = tmp;
            if (cur)
                next = cur->next;
            else
                next = nullptr;
        }
        return head;
    }
};