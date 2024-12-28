class Solution {
public:
    bool check(string &p,string &q){
        unordered_map<char,int>mp;
        for(auto i:p)mp[i]++;
        for(auto i:q)mp[i]--;
        for(auto i:mp)if(i.second!=0)return 0;
        return 1;
    }
    unordered_map<string,int>dp;
   int solve(string p,string q){
        if(p==q)return 1;
        if(p.size()!=q.size())return 0;
        if(!check(p,q))return 0;
        auto key=p+"Anshul"+q;
        if(dp.find(key)!=dp.end())return dp[key];
        int ans=0;
        for(int i=1;i<p.size();i++){
            auto curp=p.substr(0,i);
            auto curp2=p.substr(i);
            auto curq=q.substr(0,i);
            auto curq2=q.substr(i);
            auto curq3=q.substr(0,q.size()-i);
            auto curq4=q.substr(q.size()-i);
            ans|=(solve(curp,curq)&&solve(curp2,curq2));
            if(ans)return dp[key]=1;
            ans|=(solve(curp,curq4)&&solve(curp2,curq3));
            if(ans)return dp[key]= 1;

        }
        return dp[key]= ans;   
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};