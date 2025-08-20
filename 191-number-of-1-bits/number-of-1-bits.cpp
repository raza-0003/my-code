class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        if(n == 1) return 1;
        while(n){
            if(n % 2 == 1) cnt++;
            n = n / 2;
        }
        return cnt;
        
    }
};