class Solution {
public:
    // //TLE
    // unordered_map<string,long long>dp;
    // bool check(string &a,string &b){
    //     if(a.size()<b.size())return 1;
    //     if(a.size()>b.size())return 0;
    //     return a<=b;
    // }
    // bool check2(string &a,string &b){
    //     if(a.size()<b.size())return 0;
    //     return a.substr(a.size()-b.size())==b;
    // }
    
    // long long solve(string &x,string &y,string &s,int limit,string &z){
    //     if(z.size()&&check(y,z))return 0;
    //     long long ans=0;
    //     if(dp.find(z)!=dp.end())return dp[z];
    //     for(char i='0';i<=limit+'0';i++){
    //         if(i=='0'&&z.empty())continue;
    //         z.push_back(i);
    //         if(check(x,z)&&check(z,y)&&check2(z,s)){
    //             int cur=1+solve(x,y,s,limit,z);
                
    //             ans+=cur;
    //         }else ans+=solve(x,y,s,limit,z);
    //         z.pop_back();
    //     }return dp[z]= ans;
    // }
    const int mod = 1e9 + 7;
    long long dp[20][2][2]; 
    long long f(int n, string& s, bool lz, bool tight, int limit, string z, string curr){
        if(n == 0){
            return !lz;
        }
        if(dp[n][lz][tight] != -1) return dp[n][lz][tight];
        long long answer = 0;
        int ub = tight ? s[s.size() - n] - '0': limit;
        for(int i = 0; i <= min(ub, limit); i++){
            if(n <= z.size() and i == z[z.size() - n] - '0')
            answer += f(n - 1, s, lz && i == '0', tight && (i == ub), limit, z, curr + to_string(i));
            else if(n > z.size()) answer += f(n - 1, s, lz&&i == '0', tight and (i == ub), limit, z, curr + to_string(i));
        }
        return dp[n][lz][tight] = answer;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string str=to_string(finish);
        memset(dp,-1,sizeof(dp));
        long long ans2=f(str.size(),str,1,1,limit,s, "");
        str=to_string(start - 1);
        bool flag=str.size() >= s.size();
        memset(dp,-1,sizeof(dp));
        long long ans1=flag ? f(str.size(), str, 1, 1, limit, s, "") : 0;
        return ans2-ans1;
    }
};