class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>mpp;
        int left = 0;
        int right = 0;
        int maxlen = 0;
        while(right < n){
            mpp[fruits[right]]++;
            if(mpp.size() <=2){
                maxlen = max(maxlen,right-left+1);
            }
            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
                
            }
            right++;

        }
        return maxlen;
        
    }
};