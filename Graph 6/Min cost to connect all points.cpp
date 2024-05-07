 int sTree(int V, vector<vector<vector<int>>> adj)
    {
       int ans = 0;
       vector<int> vis(V, 0);
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0, 0});
       while(!pq.empty()){
           int wt = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           
           if(vis[node]) continue;
           else vis[node] = 1;
           ans+=wt;
           
           for(auto it: adj[node]){
               if(!vis[it[0]]){
                   pq.push({it[1], it[0]});
               }
           }
       }
       return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
      vector<vector<vector<int>>> adj(points.size());
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(j!=i){
                    int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    adj[i].push_back({j, dist});
                }
            }
        }
       return sTree(points.size(), adj);
    }
