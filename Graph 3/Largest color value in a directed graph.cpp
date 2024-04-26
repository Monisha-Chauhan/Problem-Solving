 int largestPathValue(string colors, vector<vector<int>>& edges) {
       int n = colors.length();
        unordered_map<int,vector<int>> graph;
        vector<int> indegree(n,0);
        
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        vector<vector<int>> charcnt(n,vector<int>(26,0));
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int visited=0,ans=0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited++;
            
            ans = max(ans,++charcnt[curr][colors[curr]-'a']);
            
            for(auto v:graph[curr]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
                for(int i=0;i<26;i++){
                    charcnt[v][i] = max(charcnt[curr][i],charcnt[v][i]);
                }
            }
        }
        
        if(visited!=n)
            return -1;
    return ans;  
    }
