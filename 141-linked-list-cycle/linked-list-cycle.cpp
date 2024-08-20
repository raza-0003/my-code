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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast= head;
        while(fast!=nullptr && fast->next!=nullptr){ ///whatever odd or even no of node it will stops
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){    // this is ensure that the is exist bcz if slow=1km/h and fast=2km/
                return true;                //net velocity is 1km if d is dis then d%1=0(definetly)
            }
        }
        return false;
       
        
    }
};