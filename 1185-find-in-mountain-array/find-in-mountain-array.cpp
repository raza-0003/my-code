/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
   int findMaximum(MountainArray &mountainArr) {
        // code here
        int n = mountainArr.length();
        if(mountainArr.get(0) > mountainArr.get(1)) return 0;
        if(mountainArr.get(n-1) > mountainArr.get(n-2)) return n-1;
        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) > mountainArr.get(mid+1)){
                return mid;
            }
            else if(mountainArr.get(mid-1) < mountainArr.get(mid)){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
    int binarySearch( MountainArray &mountainArr,int low,int high,int target){
        while(low <= high){
            int mid = low + (high-low)/2;
            if( mountainArr.get(mid) == target){
                return mid;
            }
            else if(target >  mountainArr.get(mid) ){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return -1; 
    }
     int binarySearchDescending(MountainArray &mountainArr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = mountainArr.get(mid);
            
            if (midVal == target) {
                return mid;
            }
            else if (target > midVal) {
                high = mid - 1;  // In descending array, go left for larger values
            }
            else {
                low = mid + 1;   // In descending array, go right for smaller values
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakInd = findMaximum(mountainArr);
        int lefti = binarySearch(mountainArr,0,peakInd,target);
        if(lefti != -1){
            return lefti;
        } 
        int righti = binarySearchDescending(mountainArr,peakInd+1,n-1,target);
        return righti;
        
    }
};