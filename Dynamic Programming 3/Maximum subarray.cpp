 int maxSubArray(vector<int>& nums) {
        int n=nums.size();
       
        // vector<int> dp(n,0);
        // dp[0]=nums[0];
        // int ans=nums[0];
        // for(int i=1;i<n;i++)
        // {
        //     dp[i]=max(dp[i-1]+nums[i],nums[i]);
        //     ans=max(ans,dp[i]);
        // }
        // return ans;

   //Space Optimization
        int prev=nums[0];int curr=0;
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
           curr=max(prev+nums[i],nums[i]);
           ans=max(ans,curr);
           prev=curr;
        }
        return ans;
    }
};
