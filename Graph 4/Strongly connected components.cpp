  void dfs(int node,vector<bool> &vis,vector<vector<int>>& adj,stack<int> &st)
    {
        vis[node] = true;
        for(auto i:adj[node])
        {
            if(vis[i] == false)
              dfs(i,vis,adj,st);
        }
        
        st.push(node);
    }
	 void revDFS(int node,vector<bool> &vis,vector<vector<int>> &transpose)
    {
        vis[node] = true;
        
        for(auto i:transpose[node])
        {
            if(!vis[i])
                revDFS(i,vis,transpose);
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> vis(V,false);
        stack<int> st;
        
        for(int i=0;i<V;i++)
        {
           if(!vis[i])
              dfs(i,vis,adj,st);
        }
        
        vector<vector<int>> transpose(V);
        
        for(int i=0;i<V;i++)
        {
            vis[i] = false;
            for(auto neigh:adj[i])
             transpose[neigh].push_back(i);
        }
        int count =0;
         while(!st.empty())
        {
            int top = st.top();
            st.pop();
             if(vis[top] == false)
               {   count++;
                    revDFS(top,vis,transpose);
                }
        }
        return count;
    }
