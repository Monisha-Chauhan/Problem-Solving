//Memoization
int f(int ind,int t,vector<int> nums,vector<vector<int>>& dp)
{
    if(ind==0)
    {
        return (t%nums[0]==0);
       
    }
    if(dp[ind][t]!=-1)return dp[ind][t];
    int not_take=f(ind-1,t,nums,dp);
    int take=0;
    if(nums[ind]<=t)
      take=f(ind,t-nums[ind],nums,dp);
  return dp[ind][t]=take+not_take;
}
    int change(int amount, vector<int>& coins) {
      vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
      return f(coins.size()-1,amount,coins,dp);  
    }


//Tabulation
int change(int amount, vector<int>& coins) {
      vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
    for(int t=0;t<=amount;t++)
    {
        if(t%coins[0]==0)
           dp[0][t]=1;
    }
    for(int ind=1;ind<coins.size();ind++)
    {
        for(int t=0;t<=amount;t++)
        {
            int not_pick=dp[ind-1][t];
            int pick=0;
            if(coins[ind]<=t)
              pick=dp[ind][t-coins[ind]];
            dp[ind][t]=pick+not_pick;
        }
    }
    return dp[coins.size()-1][amount];
    }


//space Optimization
 int change(int amount, vector<int>& coins) {
     vector<int> prev(amount+1,0),cur(amount+1,0);
    for(int t=0;t<=amount;t++)
    {
        if(t%coins[0]==0)
           prev[t]=1;
    }
    for(int ind=1;ind<coins.size();ind++)
    {
        for(int t=0;t<=amount;t++)
        {
            int not_pick=prev[t];
            int pick=0;
            if(coins[ind]<=t)
              pick=cur[t-coins[ind]];
         cur[t]=pick+not_pick;
        }
        prev=cur;
    }
    return prev[amount];
    }
