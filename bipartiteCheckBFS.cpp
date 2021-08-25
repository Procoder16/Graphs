#include<bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int n, vector<int> adj[], vector<int> &color){
    queue<int> bfs;
    color[n] = 0;

    bfs.push(n);
    while (!bfs.empty())
    {
        int node = bfs.front();
        bfs.pop();
        int currColor = color[node];

        for(auto it : adj[node]){
            if(color[it] == -1){
                if(currColor == 0){
                    color[it] = 1;
                }
                else{
                    color[it] = 0;
                }
                bfs.push(it);
            }
            else if(color[it] == currColor){
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
            if(!bipartiteBFS(i, adj, color)){
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
