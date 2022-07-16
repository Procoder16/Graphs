#include<iostream>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

void topoSortDFS(vector<pair<int, int>> adj[], int i, vector<int> &vis, stack<int> &topoSort){
    vis[i] = 1;

    for(auto it : adj[i]){
        if(vis[it.first] == 0){
            topoSortDFS(adj, it.first, vis, topoSort);
        }
    }

    topoSort.push(i);
    return;
}

void shortDistDGW(vector<pair<int, int>> adj[], int n){

    vector<int> vis(n, 0);
    stack<int> topoSort; 

    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            topoSortDFS(adj, i, vis, topoSort);
        }
    }

    vector<int> shortDist(n, INT_MAX);

    int node = topoSort.top();
    shortDist[node] = 0;

    while(!topoSort.empty()){
        int n = topoSort.top();
        topoSort.pop();
        for(auto it : adj[n]){
            if(shortDist[it.first] == INT_MAX){
                shortDist[it.first] = min(shortDist[it.first], shortDist[n] + it.second);
            }
        }
    }

    for(int i = 0; i < shortDist.size(); i++){
        cout<<shortDist[i]<<" ";
    }
}

int main(){

    int n, m;

    cout<<"ENTER THE NUMBER OF NODES:";
    cin>>n;
    cout<<"ENTER THE NUMBER OF EDGES:";
    cin>>m;

    vector<pair<int, int>> adj[n];

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
    }

    cout<<"SHORTEST DISTANCE ARRAY IS:";
    shortDistDGW(adj, n);

    return 0;
}