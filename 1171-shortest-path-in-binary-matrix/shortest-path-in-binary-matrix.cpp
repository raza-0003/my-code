class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0 || m == 0 || grid[0][0] == 1){
            return -1;
        }
        queue<pair<int,int>>q;
        grid[0][0] = 1;
        q.push({0,0});
        int level = 0;
        while(!q.empty()){
            int N = q.size();
            while(N!=0){
                int x = q.front().first;
                int y = q.front().second;
                if(x == n-1 && y == m-1){
                    return level + 1;
                }
                q.pop();
                for(int i=0;i<8;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0){
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
                N--;
            }
            level++;
            
        }
        return -1;
        
    }
};