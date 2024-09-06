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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* temp = head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;

        }
        int middle_index = (cnt+1)/2;
        temp=head;
        while(temp!=nullptr){
            cnt--;
            if(cnt == middle_index ){
                break;
            }
            temp=temp->next;
        }
        ListNode* delNode=temp->next;
        temp->next=delNode->next;
        delete delNode;
        return head;
    }
};