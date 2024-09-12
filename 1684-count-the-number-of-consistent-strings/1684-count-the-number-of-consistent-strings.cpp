class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        int ans=0;
        for(auto i:allowed)mp[i]++;
        for(auto i:words){
            int f=1;
            for(auto j:i){
                if(mp.find(j)==mp.end()){
                    f=0;
                    break;
                }
            }
            if(f)ans++;
        }
        return ans;
    }
};