class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascals(numRows);
        for(int i=0;i<numRows;i++){
            pascals[i].resize(i+1,1);
            for(int j=1;j<i;j++){
                pascals[i][j] = pascals[i-1][j-1] + pascals[i-1][j];
            }
        }
        return pascals;
    }
};