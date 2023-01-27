#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, rank, size;

    public:

    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUltParent(int n){
        if(n == parent[n]){
            return n;
        }

        return parent[n] = findUltParent(parent[n]);
    }

    void unionByRank(int u, int v){
        int parU = findUltParent(u);
        int parV = findUltParent(v);

        if(parU == parV)
            return;
        if(rank[parU] < rank[parV])
            parent[parU] = parV;
        else if(rank[parV] < rank[parU])
            parent[parV] = parU;
        else{
            parent[parV] = parU;
            rank[parU]++;
        }      
    }

    void unionBySize(int u, int v){
        int parU = findUltParent(u);
        int parV = findUltParent(v);

        if(parU == parV)
            return;
        if(size[parU] < size[parV])
            parent[parU] = parV;
        else{
            parent[parV] = parU;
            size[parU] += size[parV];
        }      
    }
};

int main(){

    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // if 3 and 7 belong to the same component
    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout<<"Same\n";
    }else{
        cout<<"Not same\n";
    }

    ds.unionBySize(3, 7);
    // if 3 and 7 belong to the same component
    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout<<"Same\n";
    }else{
        cout<<"Not same\n";
    }

    return 0;
}