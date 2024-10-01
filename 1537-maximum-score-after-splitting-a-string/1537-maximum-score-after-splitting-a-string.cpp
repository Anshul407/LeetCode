class Solution {
public:
    int maxScore(string s) {
        vector<int>l(s.size(),0);
        vector<int>r(s.size(),0);
        l[0]=(s[0]=='0');
        r[0]=(s.back()=='1');
        for(int i=1;i<s.size();i++){
            l[i]=l[i-1]+(s[i]=='0');
        }
        reverse(s.begin(),s.end());
        for(int i=1;i<s.size();i++){
            r[i]=r[i-1]+(s[i]=='1');
        }
        int ans=0;
        int j=l.size()-1;
        for(int i=0;i<r.size()-1;i++){
            
            ans=max(r[j-1]+l[i],ans);
            j--;
        }
        ans=max(ans,r[0]);
        return ans;
    }
};