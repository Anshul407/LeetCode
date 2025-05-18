class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(auto x:num){
            while(!st.empty()&&k&&st.top()>x-'0'){
                k--;
                st.pop();
            }
            st.push(x-'0');
        }
        while(!st.empty()&&k){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size()&&ans[i]=='0')i++;
        if(i>=ans.size())return "0";
        return ans.substr(i);
    }
};