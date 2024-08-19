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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* past = nullptr;
        ListNode* current = head;
        while(current!=nullptr){
            ListNode* aage = current->next;
            current->next=past;
            past=current;
            current=aage;
        }
        return past;

        
    }
};