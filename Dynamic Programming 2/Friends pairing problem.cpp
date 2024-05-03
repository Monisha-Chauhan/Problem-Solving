long f(int n,vector<long>& dp)
{
    if(n==0)
     return 1;
    if(dp[n]!=-1)return dp[n];
    
    long  single=f(n-1,dp);
    long pair=0;
    if(n-2>=0)
    { pair=f(n-2,dp)*(n-1);}
    
    return dp[n]=(single+pair) % 1000000007;
}
    int countFriendsPairings(int n) 
    { 
        // code hereet
        vector<long> dp(n+1,-1);
        return f(n,dp);
    }
