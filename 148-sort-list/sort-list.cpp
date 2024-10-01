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
    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int> temp;
        int left=low; // starting index of left half of arr
        int right = mid+1; // starting index of right half of arr
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    void mergeSort(vector<int> &arr,int low,int high){
        if(low>=high) return;
        int mid = (low + high)/2;
        mergeSort(arr,low,mid); // left half
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int len = arr.size();
        mergeSort(arr,0,len-1);
        temp = head;
        int i=0;
        while(temp!=nullptr){
            temp->val = arr[i];
            i=i+1;
            temp=temp->next;
        }
        return head;    
    }
};