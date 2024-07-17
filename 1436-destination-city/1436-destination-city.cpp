class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>mp;
        for(auto i:paths){
            mp[i[0]]=i[1];
        }
        string ans="";
        string it=paths[0][0];
        int x=1;
        while(x){
            ans=mp[it];
            if(mp.find(ans)==mp.end())x=0;
            else{
                it=ans;
            }

        }
        return ans;
    }
};