#include<bits/stdc++.h>
using namespace std;
int f(int x,vector<int>& dp)
{
    if (x == 1)
        return 0;
        if(dp[x]!=-1)return dp[x];
    int a =1e9;
    int b=1e9;
    int c=1e9;
    if (x % 2 == 0)
        a = f(x / 2,dp);
    if (x % 3 == 0)
        b = f(x / 3,dp);
    c = f(x - 1,dp);
    return  dp[x]=1 + min(a, min(b, c));
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int m=f(n,dp);
    cout<<m;
    return 0;
}
