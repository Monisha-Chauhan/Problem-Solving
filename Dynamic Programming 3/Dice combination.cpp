#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int> &dp)
{
    if(n==0)
    return 1;

    if(dp[n]!=-1)
    return dp[n];

    int ans = 0;
    for(int i=1;i<=6;i++)
    {
        if(n>=i)
          ans=(ans+f(n-i,dp))%1000000007;  
    }  
    return dp[n]=ans%1000000007;
}


int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<f(n,dp);

    return 0;
}
