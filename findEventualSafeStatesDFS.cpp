class Solution {

    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(vis[it] == 0){
                if(dfs(it, adj, vis, pathVis, check) == true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        vector<int> check(n, 0);

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfs(i, adj, vis, pathVis, check);
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};