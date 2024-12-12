class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check if start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) 
            return -1;
        
        // Boundary check and handling for 1x1 grid
        if (n == 1 && grid[0][0] == 0) 
            return 1;
        
        // Directions: 8 possible moves (horizontal, vertical, diagonal)
        vector<pair<int,int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},           {0,1},
            {1,-1}, {1,0}, {1,1}
        };
        
        // Queue for BFS
        queue<pair<int,int>> q;
        q.push({0,0});
        
        // Mark the start cell as visited
        grid[0][0] = 1;
        
        // Path length (starts at 1 to count the start cell)
        int pathLength = 1;
        
        // BFS
        while (!q.empty()) {
            int size = q.size();
            
            // Process all cells at current path length
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                
                // If reached destination
                if (row == n-1 && col == n-1) 
                    return pathLength;
                
                // Check all 8 neighboring cells
                for (auto& [dx, dy] : directions) {
                    int newRow = row + dx;
                    int newCol = col + dy;
                    
                    // Validate new cell
                    if (newRow >= 0 && newRow < n && 
                        newCol >= 0 && newCol < n && 
                        grid[newRow][newCol] == 0) {
                        
                        // Mark as visited and add to queue
                        grid[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            
            // Increment path length after processing all cells at current level
            pathLength++;
        }
        
        // If destination not reachable
        return -1;
    }
};