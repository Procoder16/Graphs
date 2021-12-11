#include<bits/stdc++.h>
using namespace std;

void shortDistUGUnitWeights(vector<int> adj[], int n){
    vector<int> shortDist(n, INT_MAX);
    queue<int> q;

    q.push(0);
    shortDist[0] = 0;

    while(!q.empty()){
        int node = q.front();
        int currDist = shortDist[node];
        q.pop();
        for(auto it : adj[node]){
            if((currDist + 1) < shortDist[it]){
                shortDist[it] = currDist + 1;
                q.push(it);
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

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"SHORTEST DISTANCE ARRAY FROM THE SOURCE TO ALL THE ARRAYS:";
    shortDistUGUnitWeights(adj, n);

    return 0;
}