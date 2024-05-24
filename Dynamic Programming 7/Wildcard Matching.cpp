int f(int i,int j,string& s,string& t,vector<vector<int>>& dp)
{  if(i<0 && j<0)return true;
   if(i>=0 && j<0)return false;
   if(i<0 && j>=0)
  {
     for(int p=0;p<=j;p++)
      {  if(t[p]!='*') 
           return false;}

    return true;
  }
 if(dp[i][j]!=-1)return dp[i][j];
 if(s[i]==t[j] || t[j]=='?')
  return dp[i][j]=f(i-1,j-1,s,t,dp);
 else if(t[j]=='*')
   return dp[i][j]=f(i-1,j,s,t,dp) || f(i,j-1,s,t,dp);
 return dp[i][j]=false;
}
    bool isMatch(string s, string p) {
       int n=s.size();
       int m=p.size();
    //    vector<vector<int>> dp(n,vector<int> (m,-1));
    //    return f(n-1,m-1,s,p,dp);

  vector<vector<bool>> dp(n+1,vector<bool>(m+1));
    
    dp[0][0]=true;
   
    for(int j=1;j<=m;j++)
    {
        if(p[j-1]=='*')
          dp[0][j]=true;
        else
           break;
    }
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?')
              dp[i][j]=dp[i-1][j-1];
           else if(p[j-1]=='*')
              dp[i][j]=dp[i-1][j] || dp[i][j-1];
           
        }
     }
return dp[n][m];
    }
