class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>prev(n,0);
        // traversing through the first row to store data inside dp
        for(int j=0;j<n;j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                int up = matrix[i][j] + prev[j];
                int uld = matrix[i][j];
                if(j-1>=0) uld += prev[j-1]; 
                else uld = 1e9;
                int urd = matrix[i][j];
                if(j+1<n) urd+= prev[j+1];
                else urd = 1e9;
                curr[j] = min(up,min(uld,urd));
            }
            prev = curr;
        }
        int mini = 1e9;
        for(int i=0;i<n;i++){
            mini = min(mini,prev[i]);
        }
        return mini;
    }
};