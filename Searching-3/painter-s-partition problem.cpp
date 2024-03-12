#include<bits/stdc++.h>
int countP(vector<int>& boards,int mintime)
{

 int time=0;int painters=1;
 for(auto i:boards)
 {
     time+=i;
     if(time>mintime)
      { painters++;
      time=i;
      }
       
 }
 return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
  int n=boards.size();int low=0,high=0;
  for(auto i:boards)
  { 
    low=max(low,i);
    high+=i;
  }int ans=0;
  
  while(low<=high)
  {
      int mid=low+(high-low)/2;
     int painters=countP(boards,mid);
     if(painters>k)
      {
         
          low=mid+1;
      }
      else
      { ans=mid;
        high=mid-1;}
    
  }
  return ans;
}
