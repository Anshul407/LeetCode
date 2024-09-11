class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(auto i:chars){
            mp[i]++;
        }
        int ans=0;
        for(auto i:words){
            map<char,int>temp;
            for(auto j:i){
                temp[j]++;
            }
            int f=0;
            for(auto j:temp){
                if(mp.find(j.first)==mp.end()||mp[j.first]<j.second){
                    f=1;
                    break;
                } 
            }
            if(!f)ans+=i.size();
        }
        return ans;
    }
};