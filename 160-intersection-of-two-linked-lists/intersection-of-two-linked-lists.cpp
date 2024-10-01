/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        // Traverse both lists
        while (temp1 != temp2) {
            // If temp1 reaches the end, switch to headB
            temp1 = (temp1 == nullptr) ? headB : temp1->next;

            // If temp2 reaches the end, switch to headA
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }

        // Either both will be nullptr (no intersection) or they'll meet at the intersection
        return temp1;
    }
};

