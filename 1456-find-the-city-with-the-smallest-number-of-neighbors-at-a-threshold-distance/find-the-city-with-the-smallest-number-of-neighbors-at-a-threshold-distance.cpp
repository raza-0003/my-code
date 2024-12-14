class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //solving this using floyd algorithm
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        //creating the 2D dist array
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        // marking distance node by themselves
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        //apply flloyd
        for(int via = 0 ;via<n ;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] == 1e9 || dist[via][j]== 1e9) continue;
                    dist[i][j] = min(dist[i][j],dist[i][via] + dist[via][j]);
                }
            }
        }
        int maxCount = n;
        int city = -1;
        for(int i=0;i<n;i++){
            int cnt = 0; // i--> city
            for(int j=0;j<n;j++){ // j-->adjCity
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= maxCount){
                maxCount = cnt;
                city = i;
            }
        }
        return city;
        
    }
};