#include<bits/stdc++.h>
using namespace std;
int bs(vector<int>&nums, int tar){
    int ans=-1;
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=tar){
            ans=mid;
            high=mid-1;
        }
        else if(nums[mid]<tar){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main() {
   int n,q;
   cin>>n>>q;
   vector<int>nums;
   vector<int>query;
   for(int i=0;i<n;i++){
       int a;
       cin>>a;
       nums.push_back(a);
   }
   for(int i=0;i<q;i++){
       int a;
       cin>>a;
       query.push_back(a);
   }
   sort(nums.begin(),nums.end());
   for(int i=0;i<q;i++){
       int ans=bs(nums,query[i]);
       if(ans==-1)
          cout<<0<<endl;
       else 
         cout<<n-ans<<endl;
   }
   return 0;
   
   
}
