int robber(int ind,vector<int>& nums,vector<int>& dp)
{
    if(ind==0)
    {
        return nums[ind];
    }
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
  
    int take=nums[ind]+robber(ind-2,nums,dp);
    int not_take=0+robber(ind-1,nums,dp);
  
    return dp[ind]=max(take,not_take);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n,-1); 
        vector<int> dp2(n,-1);
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(robber(temp2.size()-1,temp2,dp),robber(temp1.size()-1,temp1,dp2));
    }
