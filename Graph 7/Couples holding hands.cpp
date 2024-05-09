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
    int minSwapsCouples(vector<int>& row) {
        int count = 0;
        int n = row.size();
        DSU ds(n);
       
        for (int i = 0; i < n; i+=2) {
            ds.unionbyrank(i,i+1);
        }
        
        for (int i = 0; i < n; i += 2) {
            int left=ds.ultparent(row[i]);
            int right=ds.ultparent(row[i+1]);

            if(left!=right){
            
                ds.unionbyrank(left,right);
                count++;
            }
        }

        return count;
    }
};
