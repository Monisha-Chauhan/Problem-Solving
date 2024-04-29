vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
      
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++) {
            int a=edges[i][0];
            int b=edges[i][1];
            int t=edges[i][2];
            if(a!=b)
            {
                adj[a].push_back({b,t});
                adj[b].push_back({a,t});
            }
        }
        q.push({0,0});
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(n,0);
        dist[0]=0;
        while(!q.empty()) {
            pair<int,int>p=q.top();
            q.pop();
            int t=p.first,s=p.second;
            if(vis[s]==1)
                continue;
            if(t>=disappear[s])
                continue;
            vis[s]=1;
            for(auto i:adj[s]) {
                if(t+i.second<dist[i.first] && t+i.second<=disappear[i.first]) {
                    dist[i.first]=t+i.second;
                    q.push({t+i.second,i.first});
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++) {
            if(dist[i]<disappear[i]) 
                ans.push_back(dist[i]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
