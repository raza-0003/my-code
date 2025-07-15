class Solution {
public:
        int finMinInd(vector<int>& arr){
        int start = 0;
        int n = arr.size();
        int end = n-1;
        if(arr[start] <= arr[end]) return 0;
        int minInd = -1;
        while(start<=end){
            int mid = (start + (end-start)/2);
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                return mid;
            }
            else if(arr[0] <= arr[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return minInd;
    }
    int BS(vector<int>& arr, int key,int start,int end){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] < key){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        
        int mini = finMinInd(nums);
        
        // Search in left part (if it exists)
        if(mini > 0) {
            int left = BS(nums, target, 0, mini-1);
            if(left != -1) return left;
        }
        
        // Search in right part
        int right = BS(nums, target, mini, n-1);
        return right;
    }
};