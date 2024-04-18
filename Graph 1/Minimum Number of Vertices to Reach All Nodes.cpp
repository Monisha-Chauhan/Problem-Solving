vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n,false);
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            indegree[v]=true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==false)
            ans.push_back(i);
        }
        return ans;
    }
