 vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> ans;
      int n=nums.size();
      int first=firstOcc(nums,target);
      ans.push_back(first);
      int last=lastOcc(nums,target);
      ans.push_back(last);
      return ans;
    }
     int firstOcc(vector<int>& nums,int target )
   {
       int n=nums.size();
       int low=0,high=n-1;
       while(low<=high)
       {
           int mid=(low+high)/2;
           if(nums[mid]>target)
             high=mid-1;
            else if(nums[mid]<target)
               low=mid+1;
            else
            {
                if(mid==0 || nums[mid-1]!=nums[mid])
                  return mid;
                else
                  high  =mid-1;
                    
            }
       }
       return -1;
   }
    int lastOcc(vector<int>& nums,int target)
    {
         int n=nums.size();
       int low=0,high=n-1;
       while(low<=high)
       {
           int mid=(low+high)/2;
           if(nums[mid]>target)
             high=mid-1;
            else if(nums[mid]<target)
               low=mid+1;
            else
            {
                if(mid==n-1 || nums[mid]!=nums[mid+1])
                  return mid;
                else
                  low=mid+1;
                    
            }
       }
       return -1;

    }
