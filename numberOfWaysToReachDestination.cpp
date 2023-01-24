class Solution {
    long long mod = (long long)(1e9 + 7);
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<long long> ways(n, 0);
        vector<long long> shortestDist(n, 1e18);

        ways[0] = 1;
        shortestDist[0] = 0;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long currDist = it.first;
            long long currNode = it.second;

            for(auto it : adj[currNode]){
                long long ad = it.first;
                long long edW = it.second;

                if(currDist + edW == shortestDist[ad]){
                    ways[ad] = (ways[ad] + ways[currNode]) % mod;
                }
                else if(currDist + edW < shortestDist[ad]){
                    shortestDist[ad] = (currDist + edW);
                    pq.push({currDist + edW, ad});
                    ways[ad] = ways[currNode];
                }
            }
        }

        return ways[n - 1] % mod;
    }
};