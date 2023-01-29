class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n + 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        size.resize(n + 1, 1);
    }

    int findUltPar(int n){
        if(parent[n] == n){
            return n;
        }

        return parent[n] = findUltPar(parent[n]);
    }

    void unionBySize(int u, int v){
        int parU = findUltPar(u);
        int parV = findUltPar(v);

        if(parU == parV){
            return;
        }

        if(size[parU] < size[parV]){
            parent[parU] = parV;
            size[parV] += size[parU];
        }else{
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};

class Solution {
    bool isValid(int row, int col, int n){
        if(row >= n || row < 0 || col >= n || col < 0){
            return false;
        }
        return true;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){

                    for(int k = 0; k < 4; k++){
                        int newRow = i + delRow[k];
                        int newCol = j + delCol[k];

                        if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1){
                            int currNode = i * n + j;
                            int adjNode = newRow * n + newCol;
                            
                            ds.unionBySize(currNode, adjNode);
                        }
                    }
                }
            }
        }

        int maxSize = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    for(int k = 0; k < 4; k++){
                        int newRow = i + delRow[k];
                        int newCol = j + delCol[k];

                        if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1){
                            int adjNode = newRow * n + newCol;
                            int par = ds.findUltPar(adjNode);
                            st.insert(par);
                        }
                    }

                    int tot = 0;
                    for(auto it : st){
                        tot += ds.size[it];
                    }
                    maxSize = max(maxSize, 1 + tot);
                }
            }
        }
        
        //if the matrix has all 0's
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            maxSize = max(maxSize, ds.size[ds.findUltPar(cellNo)]);
        }

        return maxSize;
    }
};