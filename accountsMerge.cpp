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
        if(size[parU] < size[parV]){
            parent[parU] = parV;
            size[parV] += size[parU];
        }else{
            parent[parV] = parU;
            size[parU] += size[parV];
        }      
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mp;

        DisjointSet ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.count(accounts[i][j]) == 0){
                    mp[accounts[i][j]] = i;
                }else{
                    ds.unionBySize(i, mp[accounts[i][j]]);
                }
            }
        }

        vector<string> mails[n];
        for(auto it : mp){
            string mail = it.first;
            int node = it.second;

            int ultParNode = ds.findUltParent(node);
            mails[ultParNode].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){
            if(mails[i].size() == 0){
                continue;
            }

            sort(mails[i].begin(), mails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};