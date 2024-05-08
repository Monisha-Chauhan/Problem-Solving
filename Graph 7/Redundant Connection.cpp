int findparent(int n,vector<int> p)
{
    if(n==p[n])
      return n;

    return findparent(p[n],p);
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      vector<int> parent(edges.size()+1,0);
      for(int i=0;i<parent.size();i++)
      {
         parent[i]=i;
      }  
      vector<int> res;
      for(auto v:edges)
      {
        int n1=v[0];int n2=v[1];
        int p1=findparent(n1,parent);
        int p2=findparent(n2,parent);
        if(p1==p2)
          res=v;
        parent[p2]=p1;
      }
     return res;
    }
