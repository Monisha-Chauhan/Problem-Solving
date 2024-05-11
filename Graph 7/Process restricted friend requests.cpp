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


        void unionByRank(int node1, int node2) {
            
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
         DSU dsu(n);
        int a = restrictions.size(), b = requests.size();
        vector<bool> ans(b, false);
        for(int i=0; i<b; i++){
            int upa = dsu.ultparent(requests[i][0]), upb = dsu.ultparent(requests[i][1]);
            bool fg = true;
            for(int j=0; j<a; j++){
                int vpa = dsu.ultparent(restrictions[j][0]), vpb = dsu.ultparent(restrictions[j][1]);
                if(vpa == upa && vpb == upb || vpa == upb && vpb == upa){
                    fg = false;
                    break;
                }
            }
            if(fg){
                ans[i] = fg;
                dsu.unionByRank(requests[i][0], requests[i][1]);
            }
        }
        return ans;
    }
};
