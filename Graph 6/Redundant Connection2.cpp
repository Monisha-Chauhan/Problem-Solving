class DSU {
 private:
   int parent[1001];
    int rank[1001];
   
    public:
         DSU(int n) {
             for(int i = 0; i < n + 1; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        int ultparent(int node) {
            if(parent[node] == node) return node;
            return parent[node] = ultparent(parent[node]);
        }

        bool connected(int node1, int node2) {
            
            int parent1 = ultparent(node1);
            int parent2 = ultparent(node2);

            if(parent1 == parent2) return true;
            else return false;
        }

        void unionbyrank(int node1, int node2) {
            
            int parent1 = ultparent(node1);
            int parent2 = ultparent(node2);

            if(parent1 == parent2) return;
            else {
                if(rank[parent1] < rank[parent2]) {
                    parent[parent1] = parent2;
                } else if(rank[parent1] > rank[parent2]) {
                    parent[parent2] = parent1;
                } else {
                    parent[parent1] = parent2;
                    rank[parent2]++;
                }
            }
        }
    };
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int>ans;

        for(int j = edges.size() - 1; j >= 0; j--) {
              DSU graph(edges.size());
            int indegree[edges.size() + 1];
             for(int i = 0; i <= edges.size(); i++) {
                 indegree[i] = 0;
             }
             bool cycle = false;
             bool indegree2 = false;

             for(int i = 0; i < edges.size(); i++) {
                 if(j == i) continue;
                  else {
                     int u = edges[i][0];
                     int v = edges[i][1];
                     indegree[v]++;
                     if(indegree[v] == 2) {
                         indegree2 = true;
                     }
                   if(graph.connected(u, v)) {
                         cycle = true;
                     } else {
                         graph.unionbyrank(u, v);
                     }
                 }
             }
             if(cycle == false && indegree2 == false) {
                 ans.push_back(edges[j][0]);
                 ans.push_back(edges[j][1]);
                 break;
             }
        }
  return ans;
    }
