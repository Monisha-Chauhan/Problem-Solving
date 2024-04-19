bool solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(i == n-1 && j == m-1) return true; 
        vis[i][j] = true;

        bool destination = false;
        if(grid[i][j] == 1) {
            if(j+1 < m && !vis[i][j+1] && grid[i][j+1] != 2) {
               destination = solve(i,j+1,grid,vis);
            }
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] != 2) {
                destination = destination | solve(i,j-1,grid,vis);
            }
        }
        else if(grid[i][j] == 2) {
            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] != 1) {
               destination = solve(i-1,j,grid,vis);
            }
            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] != 1) {
               destination = destination | solve(i+1,j,grid,vis);
            }
        }
        else if(grid[i][j] == 3) {
            if(i+1 < n && !vis[i+1][j] && (grid[i+1][j] == 2 || grid[i+1][j] == 6 || grid[i+1][j] == 5)) {
                destination = solve(i+1,j,grid,vis);
            }
            if(j-1 >= 0 && !vis[i][j-1] && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)) {
                destination = destination | solve(i,j-1,grid,vis);
            }
        }
        else if(grid[i][j] == 4) {
            if(j+1 < m && !vis[i][j+1] && (grid[i][j+1] == 5 || grid[i][j+1] == 1 || grid[i][j+1] == 3)) {
                destination = solve(i,j+1,grid,vis);
            }
            if(i+1 < n && !vis[i+1][j] && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)) {
               destination = destination | solve(i+1,j,grid,vis);
               
            }
        } 
        else if(grid[i][j] == 5) {
            if(i-1 >= 0 && !vis[i-1][j] && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)) {
               destination = solve(i-1,j,grid,vis);
            }
            if(j-1 >= 0 && !vis[i][j-1] && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 5)) {
               destination = destination | solve(i,j-1,grid,vis);
            }
        }
        else if(grid[i][j] == 6) {
            if(i-1 >= 0 && !vis[i-1][j] && (grid[i-1][j] == 4 || grid[i-1][j] == 3 || grid[i-1][j] == 2)) {
                destination = solve(i-1,j,grid,vis);
            }
            if(j+1 < m && !vis[i][j+1] && (grid[i][j+1] == 5 || grid[i][j+1] == 3 || grid[i][j+1] == 1)) {
                destination = destination | solve(i,j+1,grid,vis);
            }
        }

        return destination;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
       int n = grid.size();
        int m = grid[0].size();       
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return solve(0,0,grid,vis);
    }
