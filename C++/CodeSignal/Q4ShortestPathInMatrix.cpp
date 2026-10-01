class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size(); 
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1; 
        queue<array<int, 3>> seen; 
        
        seen.push({0, 0, 1});
        grid[0][0] = 1; 

        while(!seen.empty()){
            auto [r, c, d] = seen.front(); 
            seen.pop(); 
            if(r == n - 1 && c == n - 1)
                return d; 
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(r + i < 0 || c + j < 0 || r + i >= n || c + j >= n)  
                        continue; 
                    if(grid[r + i][c + j] == 0){
                        seen.push({r + i, c + j, d + 1}); 
                        grid[r + i][c + j] = 1; 
                    }
                }
            }
        }
        return -1; 
    }   
};