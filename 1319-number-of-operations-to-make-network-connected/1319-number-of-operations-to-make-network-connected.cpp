class Solution {
public:
    
    vector<int> parent, rank;
    
    // find with path compression
    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    // union by rank
    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        
        if (u == v) return;
        
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // Step 1: agar wires hi kam hain → impossible
        if (connections.size() < n - 1)
            return -1;
        
        // Step 2: DSU initialize
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        int extraWires = 0;
        
        // Step 3: har edge process karo
        for (auto &e : connections) {
            int u = e[0];
            int v = e[1];
            
            // agar same parent → extra wire
            if (findParent(u) == findParent(v)) {
                extraWires++;
            }
            else {
                unionSet(u, v);
            }
        }
        
        // Step 4: components count karo
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                components++;
        }
        
        // Step 5: extra wires sufficient hain ya nahi
        if (extraWires >= components - 1)
            return components - 1;
        
        return -1;
    }
};
