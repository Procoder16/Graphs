//Bipartite Check using DFS

#include<bits/stdc++.h>
using namespace std;

bool bipartiteDFS(int n, vector<int> adj[], vector<int> &color, int currColor){
    
    if(currColor == 1 || currColor == -1){
        color[n] = 0;
    }else{
        color[n] = 1;
    }
    
    currColor = color[n];

    for(auto it : adj[n]){
        if(color[it] == -1){
            if(!bipartiteDFS(it, adj, color, currColor)){  // this was the step where mistake was made
                return false;
            }
        }
        else{
            if(color[it] == currColor){
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(int n, vector<int> adj[]){

    vector<int> color(n+1, -1);

    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!bipartiteDFS(i, adj, color, -1)){
                return false;
            }
        }
    }
    return true;
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
        cin>>u;
        int v;
        cin>>v;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    if(checkBipartite(n, adj)){
        cout<<"THE GIVEN GRAPH IS A BIPARTITE GRAPH!";
    }
    else{
        cout<<"THE GIVEN GRAPH IS NOT A BIPARTITE GRAPH!";
    }

    return 0;
}
