class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>rest(n+1,INT_MAX);
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
        }
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v,t});
        }
        rest[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(auto &[nbr,t]:adj[node]){
                if(time + t < rest[nbr]){
                    pq.push({time+t,nbr});
                    rest[nbr] = t + time;
                }
            }
        }
        vector<int>currVisited(n+1,-1);
        int totTime = 0;
        for(int i=1;i<rest.size();i++){
             if(rest[i] == INT_MAX){
                return -1;
            }
            if(currVisited[i] == -1){
                totTime  = max(rest[i],totTime);
            }
        }
        return totTime;
    }
};