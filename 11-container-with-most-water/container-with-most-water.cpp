class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxi = 0;
        while(left < right){
            int area = (right-left) * min(height[right],height[left]);
            maxi = max(maxi,area);
            // if the right side height is greater than left --> left should search for greater 
            if(height[right] > height[left]){
                left++;
            }
            // if the left side height is greater than right --> right should search for greater
            else{
                right--;
            }
        }
        return maxi;
    }
};