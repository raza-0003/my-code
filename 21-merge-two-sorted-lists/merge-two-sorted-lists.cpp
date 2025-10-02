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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        vector<int>ans;
        while(head1 && head2){
            if((head1->val) > (head2->val)){
                // element of list1 is greater
                ans.push_back(head2->val);
                head2 = head2->next;

            }
            else if((head1->val) < (head2->val)){
                // element if list2 is greater
                ans.push_back(head1->val);
                head1 = head1->next;

            }
            else{
                // both the elements are equal
                ans.push_back(head1->val);
                ans.push_back(head2->val);
                head1 = head1->next;
                head2 = head2->next;

            }
        }
        while(head1){
            ans.push_back(head1->val);
            head1 = head1->next;
        }
        while(head2){
            ans.push_back(head2->val);
            head2 = head2->next;
        }
        // building the linkedlist from the starting point
        if(ans.empty()) return nullptr;
        ListNode* head = new ListNode(ans[0]);
        ListNode* curr = head;
        for(int i=1;i<ans.size();i++){
            curr->next = new ListNode(ans[i]);
            curr = curr->next;
        }
        return head;
    }
};