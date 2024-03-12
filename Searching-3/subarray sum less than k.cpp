#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>& nums,int mid,int s)
{int sum=0;
   for(int i=0;i<mid;i++)
   {
       sum+=nums[i];
       if(sum>s)return false;
   }int j=0;
   for(int i=mid;i<nums.size();i++)
   {
       sum+=nums[i]-nums[j];
       j++;
       if(sum>s)return false;
   }
   return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int a;
         cin>>a;
         nums.push_back(a);
    }
    int s;
    cin>>s;
    int low=1;
    int high=n;int ans=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossible(nums,mid,s))
        {
            ans=mid;
            low=mid+1;
        }
        else
        high=mid-1;
           
        
    }
    cout<<ans;
    
    return 0;
}
