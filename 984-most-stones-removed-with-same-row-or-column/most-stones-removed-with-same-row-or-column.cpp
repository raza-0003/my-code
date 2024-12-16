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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol =0;
        //max row,col find size where my last stone lies in the row and in the coloumn
        for(auto it:stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0 ;
        for(auto it : stoneNodes){
            if(ds.findUParnet(it.first) == it.first){
                cnt++;
            }
        }
        return n-cnt;

    }
};