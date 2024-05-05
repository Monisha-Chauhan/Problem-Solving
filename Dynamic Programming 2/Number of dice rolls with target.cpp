//Memoization
int f(int dice,int faces,int target,vector<vector<int>>& dp)
{
   if(target<0)return 0;
   if(dice==0 && target!=0)return 0;
   if(target==0 && dice!=0)return 0;
   if(dice==0 && target==0)return 1;
   if(dp[dice][target]!=-1)return dp[dice][target];
   long long ans=0;
   for(int i=1;i<=faces;i++)
   {
    ans=ans+f(dice-1,faces,target-i,dp);
   }
   return dp[dice][target]=ans%1000000007;
}
 int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return f(n,k,target,dp); 
 }

//Tabulation
 int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
         dp[0][0]=1;
        for(int dice=1;dice<=n;dice++)
        {
            for(int tar=1;tar<=target;tar++)
            {
                 long long ans=0;
                 for(int i=1;i<=k;i++)
                { if(tar-i>=0)
                   ans=ans+dp[dice-1][tar-i];
                }
                dp[dice][tar]=ans%1000000007;
            }
        }
        return dp[n][target];
    }

//Space Optimization
    int numRollsToTarget(int n, int k, int target) {
      vector<int> prev(target+1,0);
      vector<int> curr(target+1,0);
      prev[0]=1;
      for(int dice=1;dice<=n;dice++)
        {
            for(int tar=1;tar<=target;tar++)
            {
                 long long ans=0;
                 for(int i=1;i<=k;i++)
                { if(tar-i>=0)
                   ans=ans+prev[tar-i];
                }
                curr[tar]=ans%1000000007;
            }
            prev=curr;
        }

     return prev[target];
    }
