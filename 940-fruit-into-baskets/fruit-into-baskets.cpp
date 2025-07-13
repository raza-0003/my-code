class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int n = fruits.size();
        if(n==1) return 1;
        unordered_map<int,int>mpp;
        int maxi = 0;
        while(j<n){
            int num = fruits[j];
            mpp[num]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0){
                        mpp.erase(fruits[i]);
                    }
                    i++;
                }
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};