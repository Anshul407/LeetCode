class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>univ;
        
        for(auto i:words2){
            map<char,int>mp;
            for(auto j:i)mp[j]++;
            for(auto x:mp){
                if(univ[x.first]<x.second)univ[x.first]=x.second;
            }
        }
        vector<string>ans;
        for(auto i:words1){
            map<char,int>temp;
            for(auto j:i){
                temp[j]++;
            }
            int f=0;
            for(auto v:univ){
                if(temp[v.first]<v.second){
                    f=1;
                    break;
                }
            }
            if(!f)ans.push_back(i);
        }
        return ans;
    }
};