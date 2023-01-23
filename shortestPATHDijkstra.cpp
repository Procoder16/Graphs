class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 1});
        
        vector<int> parent(n + 1), dist(n + 1, 1e9);
        
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        
        dist[1] = 0;
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            int currNode = node.second;
            int currDist = node.first;
            
            for(auto it : adj[currNode]){
                int dis = it.second;
                int ad = it.first;
                
                if(currDist + dis < dist[ad]){
                    dist[ad] = currDist + dis;
                    pq.push({dis + currDist, ad});
                    parent[ad] = currNode;
                }
            }
        }
        
        if(dist[n] == 1e9){
            return {-1};
        }
        
        vector<int> res;
        
        int node = n;
        
        while(parent[node] != node){
            res.push_back(node);
            node = parent[node];
        }
        
        res.push_back(1);
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};