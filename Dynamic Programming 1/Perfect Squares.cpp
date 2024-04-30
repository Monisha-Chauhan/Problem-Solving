int f(int n,vector<int>& dp)
 {
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int res=1e9;
    for(int i=1;i*i<=n;i++)
    {   int ps=i*i;
        int cnt=1+f(n-ps,dp);
        res=min(res,cnt);
    }
    return dp[n]=res;
 }
    int numSquares(int n) {
      vector<int> dp(n+1,-1);
      return f(n,dp);  
    }
