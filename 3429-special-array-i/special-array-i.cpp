class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return true;
        for(int i=0;i<n-1;i++){
            if((arr[i] % 2 ) == (arr[i+1] % 2)) return false;
        }
        return true;

    }
};