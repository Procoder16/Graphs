class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, -1));

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O'){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for(int i = -1; i <= 1; i++){
                int newRow = currRow + i;
                if(newRow >= 0 && newRow < m && vis[newRow][currCol] == -1 && board[newRow][currCol] == 'O'){
                    q.push({newRow, currCol});
                    vis[newRow][currCol] = 1;
                }
            }
            for(int i = -1; i <= 1; i++){
                int newCol = currCol + i;
                if(newCol >= 0 && newCol < n && vis[currRow][newCol] == -1 && board[currRow][newCol] == 'O'){
                    q.push({currRow, newCol});
                    vis[currRow][newCol] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && vis[i][j] == -1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};