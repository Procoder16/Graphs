//Cycle Detection in a directed graph using DFS

#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis){
    vis[node] = 1;
    dfsVis[node] = 1;

    for(auto it : adj[node]){
        if(vis[it] == 0){
            if(checkCycleDFS(it, adj, vis, dfsVis)){
                return true;
            }
        }
        else if(dfsVis[it]){
            return true;
        }
    }
    dfsVis[node] = 0; //returning from the current traversal
    return false;
}

bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1, 0);
    vector<int> dfsVis(n+1, 0);

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            if(checkCycleDFS(i, adj, vis, dfsVis)){
                return true;
            }
        }
    }
    return false;
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

    if(isCycle(n, adj)){
        cout<<"\nTHE GIVEN GRAPH CONTAINS A CYCLE!";
    }
    else{
        cout<<"\nTHE GIVEN GRAPH DOESN'T CONTAINS A CYCLE!";
    }

    return 0;
}