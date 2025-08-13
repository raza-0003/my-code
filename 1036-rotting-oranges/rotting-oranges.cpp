class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>>q;
        int freshOranges = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges == 0) return 0;
        int minutes = 0;
        while(!q.empty()){
            int n = q.size();
            // start multisources bfs we have to start
            while(n--){
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                for(int i=0;i<4;i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx >=0 && nx <rows && ny >=0 && ny < cols && grid[nx][ny] == 1){
                            q.push({nx,ny});
                            freshOranges--;
                            grid[nx][ny] = 2;
                        }
                }
            }
            minutes++;
        }
        if(freshOranges == 0) return minutes-1;
        // there is an fresh oranges present in the grid
        return -1;
    }
};