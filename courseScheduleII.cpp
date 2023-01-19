class Solution {
    vector<int> canFinishHelper(int n, vector<int> adj[]){
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

        if(toposort.size() == n){
            return toposort;
        }else{
            return {};
        }
    } 
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i = 0; i < prerequisites.size(); i++){
            for(int j = 0; j < 2; j++){
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
        }

        return canFinishHelper(numCourses, adj);
    }
};