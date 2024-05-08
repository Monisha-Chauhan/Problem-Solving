//Memoization + Recursion
int f(int ind,int t,vector<int> nums,vector<vector<int>>& dp)
{  if(ind==0)
{
    if(t%nums[0]==0)return t/nums[0];
    else
      return 1e9;
}
if(dp[ind][t]!=-1)return dp[ind][t];
    int not_take=f(ind-1,t,nums,dp);
    int take=INT_MAX;
    if(nums[ind]<=t)
      take=1+f(ind,t-nums[ind],nums,dp);
    return dp[ind][t]=min(take,not_take);
}
    int coinChange(vector<int>& coins, int amount) {
      vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
      int ans= f(coins.size()-1,amount,coins,dp);  
      if(ans>=1e9)return -1;
      return ans;
    }


//Tabulation
 int coinChange(vector<int>& coins, int amount) {
      vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
       for(int i=0;i<amount+1;i++)
        {
            if(i%coins[0]==0)
              dp[0][i]=i/coins[0];
            else
              dp[0][i]=1e9;
        }
        for(int ind=1;ind<coins.size();ind++)
        {
           for(int t=0;t<amount+1;t++)
           {
              int not_take=dp[ind-1][t];
               int take=INT_MAX;
            if(coins[ind]<=t)
               take=1+dp[ind][t-coins[ind]] ;
             dp[ind][t]=min(take,not_take);
           }
        }
    if (dp[coins.size()-1][amount]>=1e9)return -1;
    else
       return dp[coins.size()-1][amount];
    }


//Space Optimization
 int coinChange(vector<int>& coins, int amount) {
    //   vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
    vector<int> prev(amount+1,0);
    vector<int> curr(amount+1,0);
       for(int i=0;i<amount+1;i++)
        {
            if(i%coins[0]==0)
              prev[i]=i/coins[0];
            else
              prev[i]=1e9;
        }
        for(int ind=1;ind<coins.size();ind++)
        {
           for(int t=0;t<amount+1;t++)
           {
              int not_take=prev[t];
               int take=INT_MAX;
            if(coins[ind]<=t)
               take=1+curr[t-coins[ind]] ;
             curr[t]=min(take,not_take);
           }
           prev=curr;
        }
    if (prev[amount]>=1e9)return -1;
    else
       return prev[amount];
    }
