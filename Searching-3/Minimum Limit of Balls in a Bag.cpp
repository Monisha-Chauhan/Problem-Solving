bool isPossible(vector<int>& nums,int oper,int maxOperations)
{
    int operations=0;
    for( auto i:nums)
    {
        operations+=(i-1)/oper;
    }
    return operations<=maxOperations;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
     int n=nums.size();
     int low=1;
     int high=*max_element(nums.begin(),nums.end());int penalty=1;
     while(low<=high)
     {
        int mid=low+(high-low)/2;
       
        if(isPossible(nums,mid,maxOperations))
        {   penalty=mid;
             high=mid-1;}
        else
          low=mid+1;
     }   
     return penalty;
    }
