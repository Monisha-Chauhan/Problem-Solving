bool canplace(int n,int dist,vector<int>& stalls,int k)
{
    int cnt=1;  int last=stalls[0];
    for(int i=1;i<=n-1;i++)
    {
        if(stalls[i]-last>=dist)
        {
            cnt++;
            last=stalls[i];
        }
    }
    if(cnt>=k)return true;
    return false;
}

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());int ans=1;
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high)
        {
           int mid=low+(high-low)/2;
           if(canplace(n,mid,stalls,k))
           {
               ans=mid;
               low=mid+1;
           }
           else
             high=mid-1;
        }
        return ans;
    }
