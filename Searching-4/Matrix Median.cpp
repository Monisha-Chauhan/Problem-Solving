#include<bits/stdc++.h>
int upperBound(vector<int>& a,int n,int x)
{ int low=0,high=n-1;
int ans=n;
while(low<=high)
{
    int mid=low+(high-low)/2;
    if(a[mid] > x)
    {
        ans=mid;
        high=mid-1;
    }
    else
    low=mid+1;
}
return ans;
    
}
int countSmallEqual(vector<vector<int>>& A,int n,int m,int mid)
{
    int count=0;
    for(int i=0;i<n;i++)
     count+=upperBound(A[i],m,mid);
    return count;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int low=INT_MAX,high=INT_MIN;
    for(int i=0;i<n;i++)
    {
        low=min(low,A[i][0]);
        high=max(high,A[i][m-1]);
    }
   
    int req=(n*m)/2;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int se=countSmallEqual(A,n,m,mid);
        if(se<=req)
        {
           
            low=mid+1;
        }
        else
         high=mid-1;
    }
    return low;
}

