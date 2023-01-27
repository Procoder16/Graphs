// DSU approach

class DisjointSet{
    public:
    vector<int> parent, rank, size;

    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUltParent(int n){
        if(n == parent[n]){
            return n;
        }

        return parent[n] = findUltParent(parent[n]);
    }

    void unionByRank(int u, int v){
        int parU = findUltParent(u);
        int parV = findUltParent(v);

        if(parU == parV)
            return;
        if(rank[parU] < rank[parV])
            parent[parU] = parV;
        else if(rank[parV] < rank[parU])
            parent[parV] = parU;
        else{
            parent[parV] = parU;
            rank[parU]++;
        }      
    }

    void unionBySize(int u, int v){
        int parU = findUltParent(u);
        int parV = findUltParent(v);

        if(parU == parV)
            return;
        if(size[parU] < size[parV])
            parent[parU] = parV;
        else{
            parent[parV] = parU;
            size[parU] += size[parV];
        }      
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }

        return cnt;
    }
};