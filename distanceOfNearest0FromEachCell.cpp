class Solution {
public:

    void nearestOne(vector<vector<int>>& mat, vector<vector<int>>& vis, vector<vector<int>>& dist){
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;

            int currDist = q.front().second;
            q.pop();
            dist[currRow][currCol] = currDist;

            for(int i = -1; i <= 1; i++){
                int newRow = currRow + i;
                if(newRow >= 0 && newRow < m && vis[newRow][currCol] == -1){
                    q.push({{newRow, currCol}, currDist + 1});
                    vis[newRow][currCol] = 1;
                }
            }
            for(int i = -1; i <= 1; i++){
                int newCol = currCol + i;
                if(newCol >= 0 && newCol < n && vis[currRow][newCol] == -1){
                    q.push({{currRow, newCol}, currDist + 1});
                    vis[currRow][newCol] = 1;
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int> (n, -1));
        vector<vector<int>> dist(m, vector<int> (n, 0));

        nearestOne(mat, vis, dist);

        return dist;
    }
};