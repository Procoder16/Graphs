class Solution {
public:
    
    void dfsTraversal(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        for(int i = -1; i <= 1; i+=2){
            int newRow = i + row;
            if(newRow >= 0 && newRow < n && vis[newRow][col] == -1 && grid[newRow][col] == 1){
                dfsTraversal(grid, vis, newRow, col);
            }
        }
        for(int i = -1; i <= 1; i+=2){
            int newCol = i + col;
            if(newCol >= 0 && newCol < m && vis[row][newCol] == -1 && grid[row][newCol] == 1){
                dfsTraversal(grid, vis, row, newCol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, -1));

        int countLand = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    countLand++;
                }

                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1 && vis[i][j] == -1){
                    dfsTraversal(grid, vis, i, j);
                }
            }
        }

        int countPossible = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 1){
                    countPossible++;
                }
            }
        }

        return countLand - countPossible;
    }
};