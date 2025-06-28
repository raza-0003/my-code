class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if(board[row][i] == ch){
                // checking the row 
                return false;
            }
            if(board[i][col] == ch){
                // checking the coloumns
                return false;
            }
            if(board[3 * (row/3) + i/3][3 * (col/3) + i % 3] == ch){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    // trying out all the possible ways
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board,i,j,ch)){
                            //means ch valid hai ch ko sudoku me push karo
                            board[i][j] = ch;
                            //check karo valid ch ko ki yeh solvable hai
                            if(solve(board) == true){
                                return true;
                            }
                            else{
                                // matlab ch jo dala tha vo solveble nhi toh sudoku jaisa tha vaisa hi kardo use
                                board[i][j] = '.';
                            }
                        }
                    }
                     // means valid hi nhi hai aage ka kya faayda 
                    return false;
                }
            }
        }
        // sudoku already filled hai
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};