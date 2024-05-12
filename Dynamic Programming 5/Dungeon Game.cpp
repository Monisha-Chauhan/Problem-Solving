int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int n=dungeon.size();
      int m=dungeon[0].size();
      vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));
     
   for(int i=n-1;i>=0;i--)
   {
    for(int j=m-1;j>=0;j--)
    {  
        if(i==n-1 && j==m-1)
        {
            if(dungeon[n-1][m-1]<=0)
            dp[n-1][m-1]=-dungeon[n-1][m-1]+1;
           else
             dp[n-1][m-1]=1;
        continue;
        }

     if(dungeon[i][j]<=0)
        dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
    else
       dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]); 
    }
   }
   return dp[0][0];
    }
