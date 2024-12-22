class Solution {
public:
    int minimumTotal(vector<vector<int>>&triangle) {
        int n = triangle.size();
        vector<int>frontRow(n,0);
        for(int j=0;j<n;j++){
            frontRow[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + frontRow[j];
                int diagnal = triangle[i][j] + frontRow[j+1];
                curr[j] = min(down,diagnal);
            }
            frontRow = curr;
        }
        return frontRow[0];
        
    }
};