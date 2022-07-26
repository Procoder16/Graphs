//This code would be just the basic implementation of the Disjoint Set Data Structure

#include<iostream>
using namespace std;

int parent[10000];
int rankArr[10000];

void makeSet(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int findPar(int node){
    if(parent[node] == node){
        return node;
    }
    //This is the code without path compression
    // else{
    //     findPar(parent[node]);
    // }

    //With Path Compression
    else{
        parent[node] = findPar(parent[node]);
    }
}

void Union(int u, int v){
    u = findPar(u);
    v = findPar(v);

    if(rankArr[u] < rankArr[v]){
        parent[u] = v;
    }
    else if(rankArr[v] < rankArr[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rankArr[u]++;
    }
}

int main(){

    int n =10;
    makeSet(10);

    int m;
    cin>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        Union(u, v);
    }

    //If asked to check whether two node belon to the same component
    int a, b;

    return(findPar(a) == findPar(b));

    return 0;
}