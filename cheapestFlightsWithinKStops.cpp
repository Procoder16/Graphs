class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> shortDist(n, 1e9);

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        shortDist[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();
            
            if(stops > k){
                continue;
            }

            for(auto it : adj[node]){
                int adjNode = it.first;
                int dis = it.second;

                if(dist + dis < shortDist[adjNode] && stops <= k){
                    shortDist[adjNode] = dist + dis;
                    q.push({stops + 1, {adjNode, dist + dis}});
                }
            }
        }

        if(shortDist[dst] == 1e9){
            return -1;
        }

        return shortDist[dst];
    }
};