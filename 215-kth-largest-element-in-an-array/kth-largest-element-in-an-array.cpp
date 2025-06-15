class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        // time complexity of this O(n log (k))
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]); // log k 
            if(pq.size() > k){
                pq.pop();   // log k
            }
        }
        return pq.top();

    }
};