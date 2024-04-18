void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
 {   vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int delrow=-1;delrow<=1;delrow++)
        {
            for(int delcol=-1;delcol<=1;delcol++)
            {   if(abs(delrow)+abs(delcol)==2)continue; 
                int nrow=row+delrow;
                int ncol=col+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                 {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                 }
            }
        }
    }
 }
    int numIslands(vector<vector<char>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<int>> vis(n,vector<int> (m,0));
     int count=0;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0 && grid[i][j]=='1')
            {
                count++;
                bfs(i,j,vis,grid);
            }
        }
     }
     return count;
    }
