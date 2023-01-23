class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1){
            return -1;
        }
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> shortDist(n, vector<int> (n, 1e9));

        q.push({1, {0, 0}});

        shortDist[0][0] = 1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dist = node.first;
            int currRow = node.second.first;
            int currCol = node.second.second;

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int newRow = currRow + i;
                    int newCol = currCol + j;

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0){
                        if(dist + 1 < shortDist[newRow][newCol]){
                            shortDist[newRow][newCol] = 1 + dist;
                            q.push({dist + 1, {newRow, newCol}});
                        }
                    }
                }
            }
        }

        if(shortDist[n - 1][n - 1] == 1e9){
            return -1;
        }

        return shortDist[n - 1][n - 1];
    }
};