bool isPossible(vector<int>& bloomDay,int m,int k,int day)
{
int cnt=0;int bouq=0;
for(auto i:bloomDay)
{   if(day>=i)
        cnt++;

     else
    {
       bouq+=cnt/k;
        cnt=0;
    }
}
bouq+=cnt/k;
if(bouq>=m)return true;
return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {int low=INT_MAX,high=INT_MIN;
    int n=bloomDay.size();
    
    // if(m*n>k)return -1;
    if(m>n/k)return -1;
     for(int i=0;i<bloomDay.size();i++ )
     {
        low=min(low,bloomDay[i]);
        high=max(bloomDay[i],high);
     } 
     int ans=0;
     while(low<=high)
     {
        int mid=low+(high-low)/2;
        if(isPossible(bloomDay,m,k,mid))
           { ans=mid;
           high=mid-1;}
         else
          low=mid+1;

     }  
     return ans;
    }
