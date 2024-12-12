class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1) return diff;
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort = max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol]=newEffort;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;  
    }
};