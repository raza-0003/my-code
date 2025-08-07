class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        vector<tuple<int, int, int>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x2-x1) + abs(y2-y1);
                edges.push_back({d,i,j});
            }
        }
        int sum = 0;
        sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++){
            int d = get<0>(edges[i]);
            int u = get<1>(edges[i]);
            int v = get<2>(edges[i]);
            int u_parent = find(u);
            int v_parent = find(v);
            if(u_parent != v_parent){
                Union(u,v);
                sum += d;
            }
        }
        return sum;
    }
};