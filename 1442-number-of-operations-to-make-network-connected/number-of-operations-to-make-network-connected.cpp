#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
vector<int> size,parent,rank;
  DisjointSet(int n){
    rank.resize(n+1,0);
    size.resize(n+1,0); // ensure that no problem for 0 as well as 1 based indexing
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++){
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findUParnet(int node){
    if(node == parent[node]){ // base condition for recursion
      return node;
    }
    return parent[node] = findUParnet(parent[node]);

  }
  void unionByRank(int u,int v){
    int ulp_u = findUParnet(u);
    int ulp_v = findUParnet(v);
    if(ulp_u == ulp_v) return ;
    if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
      // no change in the rank bcoz smaller is attached to larger
    }
    else if(rank[ulp_v] < rank[ulp_u]){
      parent[ulp_v] = ulp_u;
    }
    else{
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;

    }
  }
  void unionBySize(int u,int v){
    int ulp_u = findUParnet(u);
    int ulp_v = findUParnet(v);
    if(ulp_u == ulp_v) return;
    if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else{
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        DisjointSet ds(n);
        int extraEdge = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUParnet(u) == ds.findUParnet(v)){
                extraEdge++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int Ccom = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                Ccom++;
            }
        }
        int ans = Ccom -1 ;
        if(extraEdge >= ans){
            return ans;
        }
        return -1;
        
    }
};