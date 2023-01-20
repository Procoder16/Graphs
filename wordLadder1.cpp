class Solution {
    int wordLadderBFS(string s1, string s2, set<string> &st, vector<string> &words){
        queue<pair<string, int>> q;
        q.push({s1, 1});
        st.erase(s1);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            string currWord = node.first;
            int currSeq = node.second;

            if(currWord == s2){
                return currSeq;
            }

            int len = currWord.length();
            for(int i = 0; i < len; i++){
                for(int j = 0; j < 26; j++){
                    string temp = currWord;
                    temp[i] = 'a' + j;

                    if(st.count(temp) > 0){
                        q.push({temp, currSeq + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(int i = 0; i < wordList.size(); i++){
            st.insert(wordList[i]);
        }

        return wordLadderBFS(beginWord, endWord, st, wordList);
    }
};