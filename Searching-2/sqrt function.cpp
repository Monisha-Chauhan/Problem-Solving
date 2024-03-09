 int mySqrt(int x) {long long ans=1;
     int low=1,high=x;
     if(x==1 || x==0)return x;
     while(low<=high)
     {
         long long mid=low+(high-low)/2;
         if(mid*mid==x)return mid;
         else if(mid*mid<x)
         {
             ans=mid;
             low=mid+1;
         }
         else
           high=mid-1;
     }  
    return ans; 
    }
