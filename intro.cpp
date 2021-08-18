//This file basically contains the two methods of storing the values in graph
//First I will be writing the code for the Adjacency matrix and then Adjacency List

#include<iostream>
#include<vector>
using namespace std;


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

    return 0;
}