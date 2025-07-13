class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>list;
        int i=0,j=0;
        int n = nums.size();
        vector<int>ans;
        while(j<n){
            while(list.size() > 0 && nums[j] > list.back()){
                list.pop_back();
            }
            list.push_back(nums[j]);
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans.push_back(list.front());
                if(list.front() == nums[i]){
                    list.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};