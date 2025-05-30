class Solution {
public:
    vector<int> bfs_distance(vector<int>&edges,int start){
        int n = edges.size();
        vector<int>dist(n,-1);
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(start);
        visited[start] = true;
        dist[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int next = edges[node];
            if(next != -1 && !visited[next]){
                dist[next] = dist[node] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = bfs_distance(edges,node1);
        vector<int> dist2 = bfs_distance(edges,node2);
        int minMaxDist = INT_MAX;
        int result = -1;
        for(int i=0;i<n;i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                int maxDist = max(dist1[i],dist2[i]);
                if(maxDist < minMaxDist){
                    minMaxDist = maxDist;
                    result = i;
                }
            }
        }
        return result;
    }
};