class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==0)return 0;
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            if(i.second>=2){
                ans+=(i.second/2);
            }
        }
        ans*=2;
        for(auto i:mp){
            if(i.second%2==1){
                ans++;
                break;
            }
        }
        return ans;
    }
};