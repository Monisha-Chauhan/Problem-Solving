long long f(int i,vector<vector<int>>& questions,int n,vector<long long>& dp)
 {
    if(i>=questions.size())
      return 0;
    if(dp[i]!=-1)
      return dp[i];
    long long take=questions[i][0]+f(i+1+questions[i][1],questions,n,dp);
    long long not_take=f(i+1,questions,n,dp);
    return dp[i]=max(take,not_take);
 }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        return f(0,questions,n,dp);
    }
