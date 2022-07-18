#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void topoSortDFS(int n, vector<int> adj[], vector<int> &vis, stack<int> &ele){
    vis[n] = 1;
    
    for(auto it : adj[n]){
        if(vis[it] == 0){
            topoSortDFS(it, adj, vis, ele);
        }
    }
    ele.push(n);
    return;
}

void topologicalSort(int n, vector<int> adj[]){

    vector<int> result;
    vector<int> vis(n, 0);
    stack<int> ele;

    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            topoSortDFS(i, adj, vis, ele);
        }
    }

    while(!ele.empty()){
        result.push_back(ele.top());
        ele.pop();
    }

    cout<<"TOPOLOGICAL ARRANGEMENT OF THE GIVEN GRAPH:\n";
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
}

int main(){

    int n;
    cout<<"ENTER THE NUMBER OF NODES:";
    cin>>n;

    int m;
    cout<<"ENTER THE NUMBER OF EDGES:";
    cin>>m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++){
        int u;
        cin>> u;
        int v;
        cin>> v;

        adj[u].push_back(v); // since it is a directed graph, only one side directed edge is needed
    }

    topologicalSort(n, adj);

    return 0;
}