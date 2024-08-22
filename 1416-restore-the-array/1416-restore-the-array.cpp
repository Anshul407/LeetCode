class Solution {
public:
    vector<int>dp;
    const int MOD=1e9+7;
    int solve(int st,string s,int k){
        if(st>=s.length())return 1;

        if(s[st]==0)return dp[st]= 0;
        if(dp[st]!=-1)return dp[st];
         long long num = 0;
        int ans=0;
        for(int end=st;end<s.length();end++){
            num = (num*10) + (s[end] - '0');
            if(num<1||num>k)break;
             ans = (ans%MOD + solve(end+1, s, k)%MOD)%MOD;
            
        }
        return dp[st]= ans%MOD;
    }
    int numberOfArrays(string s, int k) {
       dp.assign(s.size(), -1);

        return solve(0,s,k)%MOD;
    }
};