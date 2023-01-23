class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if(m == 1 && n == 1){
            return 0;
        }

        vector<vector<int>> shortDist(n, vector<int> (m, 1e9));
        shortDist[0][0] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});

        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {-1, 0, 1, 0};

        while(!q.empty()){
            int effort = q.front().first;
            int currRow = q.front().second.first;
            int currCol = q.front().second.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int diff = max(effort, abs(heights[newRow][newCol] - heights[currRow][currCol]));
                    if(diff < shortDist[newRow][newCol]){
                        shortDist[newRow][newCol] = diff;
                        q.push({diff, {newRow, newCol}});
                    }
                }
            }
        }

        return shortDist[n - 1][m - 1];
    }
};