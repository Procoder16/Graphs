//This file basically contains the two methods of storing the values in graph
//First I will be writing the code for the Adjacency matrix and then Adjacency List

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int n, vector<int> adj[]){

    vector<int> vis(n+1, 0); // this is the visited array

    for(int i = 1; i <= n; i++){
        if(!vis[i]){ // checking if its already visited or not
            vis[i] = 1; // marking the visisted array
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                for(auto it : adj[node]){ // loop for all the adjacents of the particular node being checked from the adjacency list
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
}

int main(){

    int n, m;
    cout<<"ENTER THE NUMBER OF NODES:";
    cin>>n;
    cout<<"ENTER THE NUMBER OF EDGES:";
    cin>>m;

    //ADJACENCY MATRIX

    // int adj[n+1][n+1] = {0};

    // for(int i = 0; i < m; i++){
    //     int u,v;
    //     cin>>u>>v;

    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    //ADJACENCY LIST
    
    vector<int> adj[n+1]; // this creates a static array of n+1 vectors
    cout<<"ENTER THE PAIRS OF NODES:"<<endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"THE BFS TRAVERSAL OF THE GRAPH IS AS FOLLOWS:"<<endl;
    bfs(n, adj);

    return 0;
}