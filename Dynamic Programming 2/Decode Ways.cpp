int f(int i,int n,string& s,vector<int>& dp)
 {
    if(i>=n)return 1;
    if(s[i]=='0')return 0;
    if(dp[i]!=-1)return dp[i];

    int onedigit=f(i+1,n,s,dp);
    int twodigit=0;
    if(i+1<n)
    {
        int fdigit=s[i]-'0';
        int sdigit=s[i+1]-'0';
        int digit=fdigit*10+sdigit;
        if(digit<=26)
          twodigit=f(i+2,n,s,dp);
    }
    return dp[i]=onedigit+twodigit;
 }
    int numDecodings(string s) {
      int n=s.size();
    //   vector<int> dp(n,-1);
    //   return f(0,n,s,dp);  
      
    vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='0')
          dp[i]=0;
        else
        {
          int onedigit=dp[i+1];
             int twodigit=0;
             if(i+1<n)
             {
            int fdigit=s[i]-'0';
           int sdigit=s[i+1]-'0';
           int digit=fdigit*10+sdigit;
            if(digit<=26)
            twodigit=dp[i+2];
       }
       dp[i]=onedigit+twodigit;
        }
    }
    return dp[0];
    }
