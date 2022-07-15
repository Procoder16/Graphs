#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topologicalSortBFS(int n, vector<int> adj[]){
    vector<int> topoSort;
    queue<int> ele;

    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++){ // initialising the indegree array
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    for(int i = 0; i < n; i++){ // pushing elements to the queue which have indegree 0
        if(indegree[i] == 0){
            ele.push(i);
        }
    }

    while(!ele.empty()){ // bfs traversing
        int node = ele.front();
        ele.pop();
        topoSort.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                ele.push(it);
            }
        }
    }

    cout<<"TOPOLOGICAL ARRANGEMENT OF THE GIVEN GRAPH IS:\n";
    for(int i = 0; i < n; i++){ 
        cout<<topoSort[i]<<" ";
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

    topologicalSortBFS(n, adj);

    return 0;
}