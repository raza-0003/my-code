class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // firstly convert it into the adjaceny node ==> {adjNode,edgeWeight}
        vector<pair<int,long long>> adj[n];
        for(auto it:roads){
            // since it is bidirectional
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // initializing the dist and ways arrays
        vector<int>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        // since source is (node 0)
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        //pushnig first element into the priority_queue {dist,node}
        pq.push({0,0});
        const int mod = 1e9 + 7;
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto it:adj[node]){
                int adjNode = it.first;
                long long edgeWeight = it.second;
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    ways[adjNode] = ways[node];
                    pq.push({dis + edgeWeight,adjNode});
                }
                else if(dist[adjNode] == dis + edgeWeight){
                    ways[adjNode] = (ways[node] + ways[adjNode])% mod;
                }

            }
        }
        return ways[n-1] % mod;
    }
};