class Solution {
public:
    unordered_map<int,string>dp;
    string solve(vector<int>&cost,int t,int c){
        if(c==t)return "";
        if(c>t)return "0";
        if(dp.count(c)>0)return dp[c];
        string op1="0";
        string cur="";
        for(int i=1;i<=9;i++){
            cur=solve(cost,t,c+cost[i-1]);
            if(cur=="0")continue;
            cur+=to_string(i);
            if(op1.size()<cur.size()){
                op1=cur;
            }    
            else if(op1.size()==cur.size())op1=max(op1,cur);
        }
        return dp[c]=op1;
    }
    string largestNumber(vector<int>& cost, int target) {
        return solve(cost,target,0);
    }
};