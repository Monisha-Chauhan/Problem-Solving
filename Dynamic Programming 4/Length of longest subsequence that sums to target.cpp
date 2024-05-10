//Memoization
int f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp)
 {

     if(target==0)return 0;
    if(ind==0)
    {
        if(nums[0]==target)
         return 1;
        else
          return -1e9;
    }
    
    if(dp[ind][target]!=-1)return dp[ind][target];
    int not_pick=f(ind-1,target,nums,dp);
    int pick=-1e9;
    if(nums[ind]<=target)
       pick=1+f(ind-1,target-nums[ind],nums,dp);

    return dp[ind][target]=max(pick,not_pick);
 }
int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
       vector<vector<int>> dp(n,vector<int> (target+1,-1));
        int ans= f(n-1,target,nums,dp);
        if(ans<0)return -1;
        return ans;
}

//tabulation
 int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
   
    vector<vector<int>> dp(n+1,vector<int> (target+1,-1e9));
   
    if(nums.size()==1)
    {
        if(nums[0]==target)return 1;
        else return -1;
    }
   
    for(int i=0;i<=n;i++)
      dp[i][0]=0;
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int tar=1;tar<=target;tar++)
        {
            int not_pick=dp[ind+1][tar];
           int pick=-1e9;
         if(tar>=nums[ind])
               pick=1+dp[ind+1][tar-nums[ind]];

           dp[ind][tar]=max(pick,not_pick);
        }
    }
    if(dp[0][target]<0)return -1;
    else return dp[0][target];

    }


