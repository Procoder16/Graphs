class Solution {

    void dfsTraversal(vector<vector<int>>& image, vector<vector<int>>& grid, int init, int sr, int sc, int color){
        grid[sr][sc] = color;
        for(int i = -1; i <= 1; i++){
            int newRow = sr + i;
            if(newRow >= 0 && newRow < image.size() && 
            grid[newRow][sc] != color && image[newRow][sc] == init){
                dfsTraversal(image, grid, init, newRow, sc, color);
            }
        }

        for(int i = -1; i <= 1; i++){
            int newCol = sc + i;
            if(newCol >= 0 && newCol < image[0].size() && 
            grid[sr][newCol] != color && image[sr][newCol] == init){
                dfsTraversal(image, grid, init, sr, newCol, color);
            }
        }
    }

    void bfsTraversal(vector<vector<int>>& image, vector<vector<int>>& grid, int init, int sr, int sc, int color){
        grid[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for(int i = -1; i <= 1; i++){
                int newRow = currRow + i;
                if(newRow >= 0 && newRow < image.size() && 
                grid[newRow][currCol] != color && image[newRow][currCol] == init){
                    grid[newRow][currCol] = color;
                    q.push({newRow, currCol});
                }
            }
            for(int i = -1; i <= 1; i++){
                int newCol = currCol + i;
                if(newCol >= 0 && newCol < image[0].size() && 
                grid[currRow][newCol] != color && image[currRow][newCol] == init){
                    grid[currRow][newCol] = color;
                    q.push({currRow, newCol});
                }
            }
        }
    }

public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        vector<vector<int>> grid(rows, vector<int>(cols));

        grid = image;

        int initialValue = image[sr][sc];

        dfsTraversal(image, grid, initialValue, sr, sc, color);

        return grid;
    }
};