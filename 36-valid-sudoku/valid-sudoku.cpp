class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // define the hash set for row,col,box(3*3)
        unordered_map<int,unordered_set<char>>row;
        unordered_map<int,unordered_set<char>>col;
        unordered_map<int,unordered_set<char>>box;
        // lets traversing through the board
        for(int i=0;i<9;i++){  // i-->row  
            for(int j=0;j<9;j++){   // j-->col
                char curr = board[i][j];
                if(curr == '.') continue;
                int boxInd = (i/3)*3 + (j/3);
                if(row[i].count(curr) || col[j].count(curr) || box[boxInd].count(curr)){
                    return false;
                }
                row[i].insert(curr);
                col[j].insert(curr);
                box[boxInd].insert(curr);
            }
        }
        return true; 
    }
};