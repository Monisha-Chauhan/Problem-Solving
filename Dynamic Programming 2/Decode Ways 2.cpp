
 long long mod=1000000007;
  long long f(int i,string& s,vector<long long>& dp)
 {
    if(i>=s.size())return 1;
    if(s[i]=='0')return 0;
   
    if(dp[i]!=-1)return dp[i];
     long long res=0,mult=1;
     if(s[i]=='*')
       mult=9;
 
    res+=mult* f(i+1,s,dp);
    if(i+1<s.size())
    {
        char next=s[i+1];
        int opts=0;
        if(s[i]=='*')
        {
            if(next=='*')
              opts=15;
            else
            {
                if(next<='6')
                   opts=2;
                else
                  opts=1;
            }
        }
        else if(s[i]<'3')
        {
            if(next=='*')
            {
                if(s[i]=='1')
                  opts=9;
                else
                  opts=6;
            }
        
            else
            {
               if(stoi(s.substr(i,2))<=26)
                opts=1;
             }
        }
        if(opts)
      res+=opts*f(i+2,s,dp);
    }
   
    return dp[i]=res%(mod);
 }
    int numDecodings(string s) {
       int  n=s.size();
       vector<long long> dp(n+1,-1);
       return f(0,s,dp);
    }
