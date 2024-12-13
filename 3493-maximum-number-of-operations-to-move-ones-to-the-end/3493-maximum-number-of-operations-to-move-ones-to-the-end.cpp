class Solution {
public:
    int maxOperations(string s) {
        int ans=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')c++;
            else if(i>0&&s[i-1]=='1')ans+=c;
        }
        return ans;
    }
};