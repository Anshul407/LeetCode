class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0,j=0;
        vector<string>ans;
        unordered_map<string,int>mp;
        while(j<s.size()){
            if(j-i+1==10){
                string cur=s.substr(i,10);
                
                mp[cur]++;
                i++;
            }
            j++;
        }
        for(auto i:mp){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};