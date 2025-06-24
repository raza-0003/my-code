class Solution {
public:
    int nextGreterInd(vector<int>& height,int ind){
        int n = height.size();
        int maxHeight = 0, maxInd = -1;
        for (int i = ind + 1; i < n; i++) {
            if (height[i] >= height[ind]) {
                return i; // First taller or equal bar found
            }
            if (height[i] > maxHeight) { // Keep track of the tallest to the right
                maxHeight = height[i];
                maxInd = i;
            }
        }
        return maxInd; 
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0;
        if(n <= 2) return 0;
        while(left < n-1 ){
            int maxInd = nextGreterInd(height,left);
            if (maxInd == -1) break;
            int minHeight = min(height[maxInd],height[left]);
            for(int i = left + 1;i<maxInd;i++){
                ans += max(0,minHeight - height[i]);
            }
            left = maxInd;
        }
        return ans;

        
    }
};