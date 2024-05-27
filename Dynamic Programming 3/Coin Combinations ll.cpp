#include<bits/stdc++.h>
using namespace std;
int f(int ind,int tar,vector<int>& nums,vector<vector<int>>& dp)
{
    if(ind==0)
     return (tar%nums[0]==0);
     if(tar==0)return 1;
    if(dp[ind][tar]!=-1)return dp[ind][tar];
     int not_take=f(ind-1,tar,nums,dp);
     int take=0;
     if(nums[ind]<=tar)
      take=f(ind,tar-nums[ind],nums,dp);
     return dp[ind][tar]=take+not_take;
     
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
      cin>>nums[i];
   int target;
   cin>>target;
   vector<vector<int>> dp(n,vector<int> (target+1,-1));
   int ans=f(n-1,target,nums,dp);
   cout<<ans;
   return 0;
      
}
