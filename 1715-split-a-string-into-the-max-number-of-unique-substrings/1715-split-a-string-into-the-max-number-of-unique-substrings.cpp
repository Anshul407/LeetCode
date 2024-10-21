class Solution {
public:
    int solve(string s,map<string,int>&mp,int j,int k,int h){
        if(j>=s.length())return k==s.length()?h:0;
        int ans=0;
        string temp="";
        for(int i=j;i<s.length();i++){
            temp+=s[i];
            if(mp.find(temp)==mp.end()){
                mp[temp]=1;
                ans=max(ans,solve(s,mp,i+1,k+temp.length(),h+1));
                mp.erase(temp);
            }          
        }
        return ans;

    }
    int maxUniqueSplit(string s) {
        map<string,int>mp;
        return solve(s,mp,0,0,0);
    }
};