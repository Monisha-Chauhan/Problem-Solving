bool isValid(int mid,vector<int>& houses,vector<int>& heaters)
{
    int m=houses.size();
    int n=heaters.size();
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(abs(heaters[i]-houses[j])<=mid)
         j++;
        else
          i++;
    }
    if(i<n)return true;
    return false;
}
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int start=0;
        int end=max(houses[houses.size()-1],heaters[heaters.size()-1]);
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isValid(mid,houses,heaters))
            {
                ans=mid;
                end=mid-1;
            }
            else
              start=mid+1;
        }
        return ans;
    }
