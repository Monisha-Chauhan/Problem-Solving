  int totalFruit(vector<int>& fruits) {
        int type1=-1,type2=-1;
        int left=0,right=0;
        int maxi=0,lastDiff=0;
        while(right<fruits.size())
        {
            if(type1==-1)
               type1=fruits[right];
            else if(type2==-1)
              type2=fruits[right];
            else if(fruits[right]!=type1 && fruits[right]!=type2)
            {
                maxi=max(maxi,right-left);
                left=lastDiff;
                 type1=fruits[left];
                 type2=fruits[right];

            }
            if(fruits[lastDiff]!=fruits[right])
              lastDiff=right;
         right++;     
             
        }
        maxi=max(maxi,right-left);
        return maxi;
    }
