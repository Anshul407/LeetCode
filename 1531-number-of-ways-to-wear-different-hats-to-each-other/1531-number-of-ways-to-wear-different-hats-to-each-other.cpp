class Solution {
public:
    vector<vector<int>>dp;
    const int mod=1e9+7;
    int solve(int hat,unordered_map<int,vector<int>>&mp,int n,int state){
        if(state==(1<<n)-1)return 1;
        if(hat<0)return 0;
        if(dp[state][hat]!=-1)return dp[state][hat];
        int ans=0;
        for(auto v:mp[hat]){
            if(state&(1<<v))continue;
            int newmask=(state|(1<<v));
            ans+=solve(hat-1,mp,n,newmask);
            ans%=mod;
        }
        ans+=solve(hat-1,mp,n,state);
        ans%=mod;
        return dp[state][hat]= ans;
    }
    int numberWays(vector<vector<int>>& hats) {
        
        int maxi=0;
        unordered_map<int,vector<int>>mp;
        dp.resize(pow(2,hats.size()+1),vector<int>(41,-1));
        for(int i=0;i<hats.size();i++){
            for(auto j:hats[i]){
                mp[j].push_back(i);
                maxi=max(maxi,j);
            }
        }
        return solve(maxi,mp,hats.size(),0);
    }
};