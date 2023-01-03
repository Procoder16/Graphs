class Solution {
    
    void dfs(int currRow, int currCol, vector<vector<int>>& grid, vector<vector<int>>& vis, int row0, int col0, vector<pair<int, int>>& vec){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[currRow][currCol] = 1;
        vec.push_back({currRow - row0, currCol - col0});
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int newRow = currRow + delRow[i];
            int newCol = currCol + delCol[i];
            
            if(newRow >= 0 && newRow < n && currRow >= 0 && currCol < m && vis[newRow][newCol] == -1 && grid[newRow][newCol] == 1){
                dfs(newRow, newCol, grid, vis, row0, col0, vec);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> st;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, -1));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, i, j, vec);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};