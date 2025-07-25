class Solution {
public:
    int dp[101][10001];
    int solve(int egg,int flr){
        if(flr == 0 || flr == 1){
            return flr;
        }
        if(egg == 1){
            return flr;
        }
        if(dp[egg][flr]!=-1){
            return dp[egg][flr];
        }
        int ans = INT_MAX;
        int low=1,high=flr,temp=0;
        while(low <= high){
            int mid = low + (high-low)/2;
            int left = solve(egg-1,mid-1);  // egg breaks
            int right = solve(egg,flr-mid); // egg does not break;
            temp = 1 + max(left,right);
            if(left < right){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
            ans = min(ans,temp);
        }

        return dp[egg][flr] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
        
    }
};