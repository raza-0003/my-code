class Solution {
public:
    int findMaxindex(vector<vector<int>>& mat,int m,int row){
        int maxValue=-1;
        int index=-1;
        for(int i=0;i<m;i++){
            if(mat[row][i]>maxValue){
                maxValue=mat[row][i];
                index=i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low + high)/2;
            int maxColIndex=findMaxindex(mat,m,mid);
            int up=mid-1>=0?mat[mid-1][maxColIndex]:-1;
            int down=mid+1<n?mat[mid+1][maxColIndex]:-1;
            if(mat[mid][maxColIndex]>up && mat[mid][maxColIndex]>down){
                return {mid,maxColIndex};
            }
            else if(mat[mid][maxColIndex]<up){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return {-1,-1};
        
    }
};