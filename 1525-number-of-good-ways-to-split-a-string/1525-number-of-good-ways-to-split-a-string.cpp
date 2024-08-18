class Solution {
public:
    
    int solve(string s,int i,vector<int>&dp,vector<int>&left,vector<int>&right){
        if(i>=s.length()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int part=0;
        

        if(left[i]==right[i+1]){
            part+=(1+solve(s,i+1,dp,left,right));
        }else part+=solve(s,i+1,dp,left,right);

        return dp[i]=part;
    }
    int numSplits(string s) {
        vector<int>dp(s.length(),-1);
        vector<int>left(s.length());
         vector<int>right(s.length());
        unordered_map<char,int>mp,mp2;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            left[i]=mp.size();
        }
         for(int i=s.length()-1;i>=0;i--){
            mp2[s[i]]++;
            right[i]=mp2.size();
        }
        return solve(s,0,dp,left,right);
    }
};