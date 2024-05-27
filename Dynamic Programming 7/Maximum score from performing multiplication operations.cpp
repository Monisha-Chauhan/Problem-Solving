int f(int ind,vector<int>& M,vector<int>& nums,int s,int e,vector<vector<int>>& dp)
{
  if(ind==M.size())
    return 0;
    if(dp[s][ind]!=-1e9)
     return dp[s][ind];

     int op1=nums[s]*M[ind]+f(ind+1,M,nums,s+1,e,dp);
     int op2=nums[e]*M[ind]+f(ind+1,M,nums,s,e-1,dp);
     return dp[s][ind]=max(op1,op2);
}
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
 int m=multipliers.size();
 vector<vector<int>> dp(m,vector<int> (m,-1e9));
 return f(0,multipliers,nums,0,nums.size()-1,dp);

    }
