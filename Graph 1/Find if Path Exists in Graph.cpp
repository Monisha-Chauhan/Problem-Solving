 bool dfs(vector<vector<int>>& graph,vector<int>& visited,int curr,int end)
 {
    if(curr==end)return true;
    if(visited[curr])return false;
     visited[curr]=1;
    for(int i=0;i<graph[curr].size();i++)
    {
        if(dfs(graph,visited,graph[curr][i],end))
          return true;
    }
    return false;

 }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>> graph(n);
      for(int i=0;i<edges.size();i++)
      {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
      } 
      vector<int> visited(n,0);
      return dfs(graph,visited,source,destination); 
    }
