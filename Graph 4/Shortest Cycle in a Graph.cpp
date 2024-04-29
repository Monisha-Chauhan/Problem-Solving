 int findShortestCycle(int n, vector<vector<int>>& edges) {
       int ans=INT_MAX;
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        
        for(int i=0;i<n;i++){
            vector<int> visited(n,INT_MAX);
            vector<int> parent(n, -1);
            visited[i]=0;
            q.push(i);
            while(!q.empty()){
                int source=q.front();
                q.pop();
                for(auto neigh:adj[source]){
                    if(visited[neigh]==INT_MAX){
                        visited[neigh]=visited[source]+1;
                        parent[neigh]=source;
                        q.push(neigh);
                    }
                    else{
                        if(parent[source]==neigh ||parent[neigh]==source) continue;
                        ans=min(ans, abs(visited[source]+visited[neigh])+1);
                    }
                }
            } 
        }
        if(ans==INT_MAX)
          return -1;
    return ans;  
    }
