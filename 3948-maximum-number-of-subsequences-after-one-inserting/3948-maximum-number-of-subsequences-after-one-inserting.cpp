class Solution {
public:
    long long help1(string &s){
        long long l=1,c=0,t=0;
        long long ans=0;
        long long cur=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='T'){
                ans+=cur;
            }
            if(s[i]=='L')l++;
            else if(s[i]=='C'){
                cur+=(l);
            }
        }
        return ans;
    }
    long long help2(string &s){
        long long l=0,c=0,t=0;
        vector<int>suff(s.size(),0);
        if(s.back()=='T')suff.back()=1;
        for(int i=s.size()-2;i>=0;i--){
            suff[i]=suff[i+1];
            if(s[i]=='T')suff[i]++;
        }
        long long ans=0;
        long long cur=0;
        long long flag=0;
        long long h=0;
        int cnt=0;
        long long maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='T'){
                ans+=cur;
            }
            if(s[i]=='L')l++;
            else if(s[i]=='C'){
                cur+=(l);
                cnt=0;
            }
            maxi=max(maxi,suff[i]*l);
        }
        maxi=max(maxi,cur);

        return ans+maxi;
    }
    long long numOfSubsequences(string s) {
        long long ans1=help1(s);
        long long ans2=help2(s);
        return max({ans1,ans2});
    }
};  