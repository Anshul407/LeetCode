class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<answers.size();i++)mp[answers[i]]++;
        for(auto i:mp){
           auto cur=ceil((double)i.second/(i.first+1));
           cur*=(i.first+1);
           ans+=cur;
        }return ans;

    }
};