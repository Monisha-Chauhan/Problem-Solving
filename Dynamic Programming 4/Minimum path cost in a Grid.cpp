int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<vector<int>> &dp) {
        int n=grid.size();
        int m=grid[0].size();
        if(i == n - 1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        for(int k=0; k<m; k++) {
            ans = min(ans, grid[i][j] + moveCost[grid[i][j]][k] + f(i + 1, k, grid, moveCost, dp));
        }
        return dp[i][j] = ans;
 }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        int  ans = 1e9;
        vector<vector<int>> dp(n, vector<int>(m, -1));

     
         for (int j = 0; j < grid[0].size(); j++) {
            ans = min(ans, f(0,j,grid,moveCost, dp));
        }

        return ans;
        
    }
