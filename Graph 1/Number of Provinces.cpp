 void dfs(int curr,vector<int> adj[],vector<int>& visited)
 {
    visited[curr]=1;
    for(auto i:adj[curr])
    {
        if(visited[i]==0)
        {
            dfs(i,adj,visited);
        }
    }
 }
    int findCircleNum(vector<vector<int>>& isConnected) {
     int V=isConnected.size();
     vector<int> adj[V];
     for(int i=0;i<V;i++)
     {
        for(int j=0;j<V;j++)
        {
            if(isConnected[i][j]==1 && i!=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
     }  
     vector<int> visited(V,0);
     int count=0;
     for(int i=0;i<V;i++)
    {
        if(visited[i]==0)
        {
            count++;
            dfs(i,adj,visited);
        }
    } 
    return count;
    }
