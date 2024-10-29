class Solution {
public:
    string thousandSeparator(int n) {
        string x=to_string(n);
        int cnt=0;
        string ans="";
        for(int i=x.size()-1;i>=0;i--){
            if(cnt==3){
                ans+=".";
                cnt=0;
            }
            ans+=x[i];
            cnt++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};