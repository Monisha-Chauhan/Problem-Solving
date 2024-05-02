int solve(int n,vector<vector<int>>& mat,int r,int c,vector<vector<int>>& dp){

        if(c>=n)return 0;

        if(dp[r][c]!=-1)return dp[r][c];

        int take=mat[r][c]+max(solve(n,mat,1,c+2,dp),solve(n,mat,0,c+2,dp));

            int not_take1=solve(n,mat,1,c+1,dp);

            int not_take2=solve(n,mat,0,c+1,dp);

        return dp[r][c]=max(take,max(not_take1,not_take2));   
}
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
         vector<vector<int>> dp(3,vector<int>(N+1,-1));

        return max(solve(N,mat,0,0,dp),solve(N,mat,1,0,dp));
    }
