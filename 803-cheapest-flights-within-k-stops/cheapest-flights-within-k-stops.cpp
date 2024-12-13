class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // firstly convert it into adjList
        vector<pair<int,int>>adj[n];
        //adj ==> {adjNode,cost(distance)}
        // flights ==> [srcNode,dstNode,cost]
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // queue ==> {stops,node,dis}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src] = 0;
        // now performing djkestra algo
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) continue; // no need to go for further adjacent node;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(cost + edgeWt < dist[adjNode]){
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];


        
    }
};