class Solution {
public:

    void bfsTraversal(vector<int> adj[], int node, vector<int> &vis){
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int n = q.front();
            q.pop();
            vis[n] = 1;
            for(auto it : adj[n]){
                if(vis[it] == -1){
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];

        for(int i = 0; i < V; i++){
            for(int j = 0; j < isConnected[i].size(); j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int noOfProvinces = 0;

        vector<int> vis(V, -1);

        for(int i = 0; i < V; i++){
            if(vis[i] == -1){
                noOfProvinces++;
                bfsTraversal(adj, i, vis);
            }
        }

        return noOfProvinces;
    }
};