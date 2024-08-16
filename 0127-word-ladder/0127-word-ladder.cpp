class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_map<string,int>list;
        for(auto i:wordList){
            list[i]++;
        }
        unordered_map<string,int>vis;
        vis[beginWord]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string w=it.first;
            int dist=it.second;
            if(w==endWord)return dist;

            for(int i=0;i<w.length();i++){
                char original=w[i];
                for(char x='a';x<='z';x++){
                    w[i]=x;
                    if(list[w]&&!vis[w]){q.push({w,dist+1});vis[w]=1;}
                }
                w[i]=original;
            }
        }
        return 0;

    }
};