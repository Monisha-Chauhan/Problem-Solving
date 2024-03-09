 int findMin(vector<int>& nums) {
      int n=nums.size(); int ind=-1;
      int low=0,high=n-1;int mini=INT_MAX;
      while(low<=high)
      {
          int mid=(low+high)/2;
          if(nums[low]<=nums[mid])
          {
             
            if(mini>nums[low])
            {
              mini=nums[low];
              ind=low;
            }
              low=mid+1;
          }
          else
          {
               if(mini>nums[mid])
            {
              mini=nums[mid];
              ind=mid;
            }
              high=mid-1;
          }
      } 
      return ind; 
    }
