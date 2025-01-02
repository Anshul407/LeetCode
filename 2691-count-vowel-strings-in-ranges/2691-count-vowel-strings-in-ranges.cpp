class Solution {
public:
    bool vow(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 1;
        return 0;
    }
    int count(string &w){
        return vow(w[0])&&vow(w[w.size()-1]);
       
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>pf(words.size(),0);
        pf[0]=count(words[0]);
        for(int i=1;i<pf.size();i++){
            pf[i]=pf[i-1]+count(words[i]);
        }
        vector<int>ans;
        for(auto i:queries){
            int u=i[0];
            int v=i[1];
            if(u==0)ans.push_back(pf[v]);
            else{
                ans.push_back(pf[v]-pf[u-1]);
            }
            
        }
        return ans;
    }
};