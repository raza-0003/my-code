class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<p>maxH;
        int n = points.size();
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            maxH.push({dist,{x,y}});
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        while(!maxH.empty()){
            int x = maxH.top().second.first;
            int y = maxH.top().second.second;
            ans.push_back({x,y});
            maxH.pop();
        }
        return ans;
        
    }
};