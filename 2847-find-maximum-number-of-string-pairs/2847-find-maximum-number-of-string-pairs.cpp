class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,int>mp;
        int cnt=0;
        for(auto i:words){
            string x=i;
            reverse(i.begin(),i.end());
            if(mp.find(i)!=mp.end())cnt++;
            mp[x]++;
        }
        
        
        return cnt;
    }
};