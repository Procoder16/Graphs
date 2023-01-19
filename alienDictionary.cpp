class Solution{
    private:
    vector<int> topo(int n, vector<int> adj[]){
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> toposort;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return toposort;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0; i < N - 1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            int len = min(s1.length(), s2.length());
            for(int i = 0; i < len; i++){
                if(s1[i] != s2[i]){
                    adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topoSort = topo(K, adj);
        
        string ans = "";
        for(auto it : topoSort){
            ans += it + 'a';
        }
        
        return ans;
    }
};