bool isPossible(string s,string t,int mid,int maxCost)
 {
    int len=0;int cost=0;int length=0;int j=0;
    for(int i=0;i<s.size();i++)
    { cost+=abs(s[i]-t[i]);
       if(cost<=maxCost)
         { len++;
         length=max(length,len);}
        else
          {
           cost-=abs(s[j]-t[j]);j++;
          }
    }
    if(length>=mid)return true;
    return false;
 }
  int equalSubstring(string s, string t, int maxCost) {
    int n=s.size();int ans=0;
    int low=0,high=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(isPossible(s,t,mid,maxCost))
        {
            ans=mid;
            low=mid+1;

        }
        else
           high=mid-1;
    }
    return ans;

    }
