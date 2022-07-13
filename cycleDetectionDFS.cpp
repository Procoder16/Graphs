//Cycle Detection in a Graph using DFS
#include<iostream>
#include<queue>
using namespace std;

bool checkCycleDFS(int i, vector<int> adj[], vector<int> &vis, int par){
    vis[i] = 1;
    
    for(auto it : adj[i]){
        if(vis[it] == 0){
            if(checkCycleDFS(it, adj, vis, i)){
                return true;
            }             
        }
        else if(it != par){
            return true;
        }        
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            if(checkCycleDFS(i, adj, vis, -1)){
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

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isCycle(n, adj)){
        cout<<"\nTHE GIVEN GRAPH CONTAINS A CYCLE!";
    }
    else{
        cout<<"\nTHE GIVEN GRAPH DOESN'T CONTAINS A CYCLE!";
    }

    return 0;
}