class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>newa(score.begin(),score.end());
        sort(newa.begin(),newa.end());
        reverse(newa.begin(),newa.end());
        unordered_map<int,string>mp;
        for(int i=0;i<newa.size();i++){
            if(i==0){
                  mp[newa[i]]="Gold Medal";
            }
            else if(i==1){
                mp[newa[i]]="Silver Medal";
            }
            else if(i==2){
                mp[newa[i]]="Bronze Medal";
            }else{
                mp[newa[i]]=to_string(i+1);
            }
        }
        vector<string>ans;
        for(auto i:score){
            ans.push_back(mp[i]);
        }
        return ans;

    }
};