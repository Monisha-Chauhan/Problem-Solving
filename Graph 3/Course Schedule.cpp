 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     vector<int> adj[numCourses];
     for(auto i:prerequisites)
       adj[i[0]].push_back(i[1]);
     vector<int> indegree(numCourses,0);
     for(int i=0;i<numCourses;i++)
     {
        for(auto it:adj[i])
           indegree[it]++;
     }   
     queue<int> q;
     for(int i=0;i<numCourses;i++)
     {
        if(indegree[i]==0)
          q.push(i);
     }
     vector<int> topo;
     while(!q.empty())
     {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto i:adj[node])
        {
            indegree[i]--;
            if(indegree[i]==0)q.push(i);
        }
     }
     if(topo.size()==numCourses)return true;
      return false;
    }
