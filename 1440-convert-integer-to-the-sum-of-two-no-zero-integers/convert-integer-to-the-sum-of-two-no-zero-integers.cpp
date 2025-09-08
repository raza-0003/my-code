class Solution {
public:

    bool isContainZero(int n){
        while(n){
            int digit = n % 10;
            if(digit == 0) return true;
            n /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        // brute force approach
        vector<int>ans;
        if(n == 2) return {1,1};
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        for(int i=0;i<ans.size();i++){
            int a = ans[i];
            for(int j=i+1;j<ans.size();j++){
                if(ans[j] + a == n && !isContainZero(a) && !isContainZero(ans[j])){
                    return {a,ans[j]};
                    break;
                }
            }
        }
        return {};
    }
};