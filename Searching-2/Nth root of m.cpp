	int powern(int mid,int n,int m)
{
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*mid;
        if(ans>m)return 2;
    }
    if(ans==m)return 1;
    return 0;
}
	int NthRoot(int n, int m)
	{
	    int low=1,high=m;
	   if(m==0 || m==1)return m;
	   while(low<=high)
	   {
	       long long mid=low+(high-low)/2; 
	       long long nsq=powern(mid,n,m);
	       if(nsq==1)return mid;
	       else if(nsq==0)
	        low=mid+1;
	       else
	         high=mid-1;
	   }
	   return -1;
	}  
