class Solution {
public:
    vector<int> countBits(int n) {
        bitset<32>b;
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            bitset<32>bits(i);
            ans[i] = bits.count();
        }
        return ans;
    }
};