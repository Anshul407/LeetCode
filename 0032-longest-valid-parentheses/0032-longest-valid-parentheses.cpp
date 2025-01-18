class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>dp(s.size(),0);
       stack<int>temp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')temp.push(i);
            else {
                if(!temp.empty()){
                    auto cur=temp.top();
                    temp.pop();
                    auto newcur=i-cur+1;
                    dp[i]=newcur;
                    if(cur>1){
                        dp[i]+=dp[cur-1];
                    }
                }
            }
        }
        int ans=0;
        for(auto i:dp){
            ans=max(ans,i);
        }
        return ans;

    }
};