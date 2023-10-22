class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>st(wordList.begin(),wordList.end());
        while(!q.empty()){
            string w=q.front().first;
            int step=q.front().second;
            q.pop();
            if(w==endWord)return step;
            for(int i=0;i<w.length();i++){
                char org=w[i];
                for(char ch='a';ch<='z';ch++){
                    w[i]=ch;
                    if(st.find(w)!=st.end()){
                        st.erase(w);
                        q.push({w,step+1});

                    }
                    w[i]=org;
                }
            }
        }
        return 0;
        
    }
};