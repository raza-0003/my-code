class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        vector<int>prev;
        for(int row=0;row<numRows;row++){
            vector<int>curr(row+1,1);
            for(int col=1;col<row;col++){
                curr[col] = prev[col-1] + prev[col];
            }
            result.push_back(curr);
            prev = curr;
        }
        return result;
    }
};