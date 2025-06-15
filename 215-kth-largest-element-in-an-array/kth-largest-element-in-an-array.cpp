class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<k;i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;

    }
};