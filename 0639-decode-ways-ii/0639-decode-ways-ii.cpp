class Solution {
public:
    const int mod=1e9+7;
    int dp[100001];
    int solve(string &s,int i){
        if(i>=s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        auto cur=s[i];
        int ans=0;
        if(cur=='*'){
            for(int x=1;x<=9;x++)ans=(ans+solve(s,i+1))%mod;
            if(i+1<s.size()){
                auto cur2=s[i+1];
                if(cur2=='*'){
                    for(int t=1;t<=2;t++){
                        for(int k=1;k<=9;k++){
                            if(t*10+k<=26)ans=(ans+solve(s,i+2))%mod;
                        }
                    }
                }else{
                    int num=cur2-'0';
                    if(num==0)ans=(ans+solve(s,i+2)*2)%mod;
                    else{
                    for(int t=1;t<=2;t++){
                        if(t*10+num<=26)ans=(ans+solve(s,i+2))%mod;
                    }}
                }
            }
        }else{
            int curnum=s[i]-'0';
            if(curnum!=0){
            ans=(ans+solve(s,i+1))%mod;
            if(i+1<s.size()){
                auto cur2=s[i+1];
                if(cur2=='*'){
                    for(int p=1;p<=9;p++){
                        if(curnum*10+p<=26)ans=(ans+solve(s,i+2))%mod;
                    }
                }else{
                    auto nextnum=cur2-'0';
                    if(curnum*10+nextnum<=26)ans=(ans+solve(s,i+2))%mod;
                }
            }}
        }
        return dp[i]= ans;    
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};