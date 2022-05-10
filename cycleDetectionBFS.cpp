//cycle detection in an undirected graph using BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool checkCycle(int i, vector<int> adj[], vector<int> &vis){
    vis[i] = 1;
    queue<pair<int,int>> q;

    q.push({i,-1});

    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push({it, node});
            }
            else{
                if(it != prev){
                    return true;
                }
            }            
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            if(checkCycle(i, adj, vis)){
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