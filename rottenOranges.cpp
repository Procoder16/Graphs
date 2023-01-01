class Solution {
    int rottenOrangesHelper(vector<vector<int>>& grid, vector<vector<int>>& vis, int &time){
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<pair<int, int>, int>> q;

        int countFresh = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                if(grid[i][j] == 1){
                    countFresh++;
                }
            }
        }

        int countUpdated = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;

            int currTime = q.front().second;
            q.pop();
            time = currTime;

            for(int i = -1; i <= 1; i++){
                int newRow = row + i;
                if(newRow >= 0 && newRow < grid.size() && 
                grid[newRow][col] == 1 && vis[newRow][col] == -1){
                    vis[newRow][col] = 2;
                    q.push({{newRow, col}, currTime + 1});
                    countUpdated++;
                }
            }
            for(int i = -1; i <= 1; i++){
                int newCol = col + i;
                if(newCol >= 0 && newCol < grid[0].size() && 
                grid[row][newCol] == 1 && vis[row][newCol] == -1){
                    vis[row][newCol] = 2;
                    q.push({{row, newCol}, currTime + 1});
                    countUpdated++;
                }
            }
        }
        return (countFresh != countUpdated) ? -1 : time;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> vis(row, vector<int> (col, -1));

        int time = 0;

        return rottenOrangesHelper(grid, vis, time);
    }
};