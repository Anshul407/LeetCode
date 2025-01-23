class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        map<char,int>x;
        for(auto i:mp){
            if(i.second==maxi)x[i.first]++;
        }
        string ans;
        for(int i=s.size()-1;i>=0;i--){
            if(x.find(s[i])!=x.end()){
                ans.push_back(s[i]);
                x.erase(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};