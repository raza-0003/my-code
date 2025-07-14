class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        if (n == 1) return nums[0];
        if (nums[left] < nums[right]) return nums[left];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                return nums[mid];
            }
            else if (nums[0] <= nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1; // Should never reach here as per problem constraints
    }
};
