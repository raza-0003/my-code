class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1){
            return -1;
        }
        if(n == 1 && m == 1){
            return 1;
        }
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        // since all the weight of the edges is 1 that why i able to use the queue
        queue<P>pq;
        grid[0][0] = 1;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            pair<int,int> node = pq.front().second;
            int d = pq.front().first;
            int x = node.first;
            int y = node.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && d + 1 < dist[nx][ny]){
                    grid[nx][ny] = 1;
                    pq.push({d +1, {nx,ny}});
                    dist[nx][ny] = d + 1;
                }
            }
        }
        if(dist[n-1][m-1] == INT_MAX){
            return -1;
        }        
        return dist[n-1][m-1]+1;

    }
};