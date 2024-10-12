class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp;
         int ans=0;
        for(auto i:words1)mp[i]++;
        unordered_map<string,int>mp2;
        for(auto i:words2)mp2[i]++;
        for(auto i:mp)if(i.second==1&&mp2[i.first]==1)ans++;

       
       
        return ans;


    }
};