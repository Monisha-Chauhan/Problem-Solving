
// Memoization Solution 1
// int f(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp)
// {
//     if(ind==nums.size())return 0;
//     if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
//     int len=0+f(ind+1,prev_ind,nums,dp);
//     if(prev_ind==-1 || nums[ind]>nums[prev_ind])
//       len=max(len,1+f(ind+1,ind,nums,dp));
//     return dp[ind][prev_ind+1]=len;
// }
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(),vector<int> (nums.size()+1,-1));
        // return f(0,-1,nums,dp);

        // DP( Tabulation)-  Solution 2
    //     int n=nums.size();
    //     vector<int> dp(n,1);
    //     int maxi=1;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<i;j++)
    //         {
    //             if(nums[j]<nums[i])
    //               dp[i]=max(dp[i],1+dp[j]);
    //         }
    //         maxi=max(maxi,dp[i]);
    //     }
    //  return maxi;

    // using Binary Search Solution 3
     vector<int> temp;
     temp.push_back(nums[0]);
     for(int i=1;i<nums.size();i++)
     {
        if(nums[i]>temp.back())
           temp.push_back(nums[i]);

        else
        {
            int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[ind]=nums[i];
        }
     }
     return temp.size();
    }
