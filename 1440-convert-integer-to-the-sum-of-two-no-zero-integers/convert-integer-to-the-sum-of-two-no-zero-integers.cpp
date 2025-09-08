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
        vector<int> ans;
        if(n == 2) return {1,1};
        for(int i=1;i<n;i++){
            int a = i;
            int b = n - i;
            if(!isContainZero(a) && !isContainZero(b)){
                return {a,b};
            }
        }
        return {};
    }
};
