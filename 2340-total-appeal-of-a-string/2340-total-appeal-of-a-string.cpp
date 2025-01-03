class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        for(auto ch='a';ch<='z';ch++){
            long long cur=0;
            for(long long i=0;i<s.size();i++){
                if(s[i]==ch)cur=i+1;
                ans+=cur;
            }
        }
        return ans;
    }
};