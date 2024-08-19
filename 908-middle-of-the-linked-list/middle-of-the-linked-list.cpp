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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt1=0;
        while(temp->next!=nullptr){
            cnt1++;
            temp=temp->next;
        }
        temp = head;
        int cnt2=0;
        while(temp->next!=nullptr){
            cnt2++;
            if(cnt1%2==1){
                //odd vala case
                if(cnt2==cnt1/2+1){
                    return temp->next;

                }
                
            }
            else{
                if(cnt2==cnt1/2){
                    return temp->next;
                }

            }
            temp=temp->next;

        }
        return temp;
        
    }
};