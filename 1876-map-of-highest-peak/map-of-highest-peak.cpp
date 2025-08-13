class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>>q;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>height(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 1){
                    // this the source forhitting the mu;tisource bfs
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int q_size = q.size();
            while(q_size--){
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m &&  height[nx][ny] == -1){
                        height[nx][ny] = 1 + height[x][y];
                        q.push({nx,ny});
                    }
                }
            }
        }
        return height;
    }
};