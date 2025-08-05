class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            pair<int,int> node = pq.top().second;
            int diff = pq.top().first;
            int x = node.first;
            int y = node.second;
            if(x == n-1 && y == m-1){
                return diff;
            }
            pq.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >=0 && ny < m){
                    int absDiff = abs(heights[nx][ny] - heights[x][y]);
                    int maxDiff = max(diff,absDiff);
                    if(maxDiff < dist[nx][ny]){
                        dist[nx][ny] = maxDiff;
                        pq.push({maxDiff,{nx,ny}});
                    }
                    
                }
            }
        }
        return dist[n-1][m-1];

        
    }
};