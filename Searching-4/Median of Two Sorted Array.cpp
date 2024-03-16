    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   int n=nums1.size();
   int m=nums2.size();
   if(n>m)return findMedianSortedArrays(nums2,nums1);
//    int low=max(0,(n+m)/2-m);
//    int high=min(n,(n+m)/2);
int low=0,high=n;
   
   while(low<=high)
   {
    int amid=low+(high-low)/2;
    int bmid=((n+m+1)/2)-amid;
    int aleft=(amid==0)?INT_MIN:nums1[amid-1];
    int bleft=(bmid==0)?INT_MIN:nums2[bmid-1];
    int aright=(amid==n)?INT_MAX:nums1[amid];
    int bright=(bmid==m)?INT_MAX:nums2[bmid];
if(aleft<=bright && bleft<=aright)
{if((m+n)%2==0)
  return (max(aleft,bleft)+min(aright,bright))/ 2.0;
else
return (double)max(aleft,bleft);
}
  
 else if(aleft>bright)
  high=amid-1;
  else 
    low=amid+1;
   }
   return -1;
    }
