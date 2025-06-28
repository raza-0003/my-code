class Solution {
public:
    bool Find(vector<vector<char>>& board, string word,int r,int c,int ind,vector<vector<bool>>&visited){
        if(ind == word.size()) return true;
        // now checking boundry condition
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || word[ind] != board[r][c] || visited[r][c] == true){
            return false;
        }
        visited[r][c] = true;
        bool res = (Find(board,word,r,c+1,ind+1,visited) || Find(board,word,r,c-1,ind+1,visited) || Find(board,word,r+1,c,ind+1,visited) || Find(board,word,r-1,c,ind+1,visited));
        visited[r][c] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(Find(board,word,i,j,0,visited)) return true;
            }
        }
        return false;  
    }
};