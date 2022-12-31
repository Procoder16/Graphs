class Solution {
    void bfsTraversal(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;

            q.pop();

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int newRow = currRow + i;
                    int newCol = currCol + j;

                    if(newRow >= 0 && newRow < totalRow && newCol >= 0 && newCol < totalCol
                    && grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0){
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }
  public:

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> vis(rows, vector<int> (cols, 0));

        int count = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    count++;
                    bfsTraversal(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};
