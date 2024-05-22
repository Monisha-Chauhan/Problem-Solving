 int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];

                }
                else if(nums[j]<nums[i] && dp[i]==1+dp[j])
                  cnt[i]+=cnt[j];
            }
              maxi=max(dp[i],maxi);
        }
        int nos=0;
        for(int i=0;i<n;i++)
        {
          if(dp[i]==maxi)
            nos+=cnt[i];
        }
        return nos;
    }
};
