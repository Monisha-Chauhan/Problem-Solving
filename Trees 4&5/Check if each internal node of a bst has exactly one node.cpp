bool hasOnlyOneChild(vector<int> pre)
{
    int nextDifference, lastDifference;
    for(int i=0; i<pre.size()-1; i++)
    {   nextDifference = pre[i] - pre[i+1];
        lastDifference = pre[i] - pre[size-1];
        if(nextDifference*lastDifference < 0)
            return false;
    }
    return true;
}
 

