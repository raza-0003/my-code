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
    ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    std::vector<int> arr;
    ListNode* temp = head;

    // Collecting odd-indexed nodes (1st, 3rd, 5th, etc.)
    while (temp != nullptr) {
        arr.push_back(temp->val);
        temp = (temp->next != nullptr) ? temp->next->next : nullptr;
    }
    
    temp = head->next;

    // Collecting even-indexed nodes (2nd, 4th, 6th, etc.)
    while (temp != nullptr) {
        arr.push_back(temp->val);
        temp = (temp->next != nullptr) ? temp->next->next : nullptr;
    }
    
    temp = head;
    int i = 0;
    
    // Reassigning values to the linked list
    while (temp != nullptr) {
        temp->val = arr[i];
        temp = temp->next;
        i++;
    }
    
    return head;
}

   
        
    
};