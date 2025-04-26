class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        map<int,pair<int,int>>mp;
        for(int i=0;i<conversions.size();i++){
            mp[conversions[i][1]]={conversions[i][0],conversions[i][2]};
        }vector<int>dp(conversions.size()+1,0);
        int mod=1e9+7;
        for(int i=0;i<conversions.size()+1;i++){
            if(i==0)dp[i]=1;
            else{
                auto cur=mp[i];
                long long s=cur.second;
                while(cur.first!=0){
                    cur=mp[cur.first];
                    s=(s%mod*cur.second%mod)%mod;
                    if(dp[cur.first]!=0){
                        s=(s%mod*dp[cur.first]%mod)%mod;
                        break;
                    }
                    s%=mod;
                }
                dp[i]=s;
            }
        }return dp;
    }
};