 bool dfs(int curr,vector<int> adj[],vector<int>& vis,vector<int>& pathV)
  {
      vis[curr]=1;
      pathV[curr]=1;
      for(auto i:adj[curr])
      {
          if(vis[i]==0)
          {
              if(dfs(i,adj,vis,pathV)==true)
               return true;
          }
          else if(pathV[i])
           return true;
      }
      pathV[curr]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathV(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathV)==true)
                 return true;
            }
        }
        return false;
    }
