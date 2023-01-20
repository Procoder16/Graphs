#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> findSequencesHelper(string beginWord, string endWord, vector<string>& wordList, set<string> &st){
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedWords;
        usedWords.push_back(beginWord);
        vector<vector<string>> ans;
        
        int len = 0;
        
        while(!q.empty()){
            vector<string> list = q.front();
            q.pop();
            if(list.size() > len){
                len++;
                for(auto it : usedWords){
                    st.erase(it);
                }
            }
            
            string currWord = list.back();
            if(currWord == endWord){
                if(ans.size() == 0){
                    ans.push_back(list);
                }else if(ans[0].size() == list.size()){
                    ans.push_back(list);
                }
            }
            for(int i = 0; i < currWord.length(); i++){
                char original = currWord[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    currWord[i] = ch;
                    if(st.count(currWord) > 0){
                        list.push_back(currWord);
                        q.push(list);
                        usedWords.push_back(currWord);
                        list.pop_back();
                    }
                }
                currWord[i] = original;
            }
        }
        
        return ans;
    }
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        st.insert(wordList.begin(), wordList.end());
        
        return findSequencesHelper(beginWord, endWord, wordList, st);
    }
};

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}