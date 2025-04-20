class Solution {
public:
    bool check(vector<int>&mp,vector<int>&mp2){
        for(int i=0;i<150;i++){
            if(mp[i]<mp2[i])return 0;
        }
        return 1;
    }
    string minWindow(string s, string t) {
        int i=0,j=0;
        int ans=INT_MAX;
        vector<int>mp(150,0),mp2(150,0);
        string cur="";
        for(auto i:t)mp2[i-'A']++;
        while(j<s.size()){
            mp[s[j]-'A']++;
            int f=0;
            while(check(mp,mp2)){
                mp[s[i]-'A']--;
                f=1;
                i++;  
            }
            if(f){
                if(ans>(j-i+1)){
                    ans=j-i+1;
                    cur=s.substr(i-1,j-i+2);
                }
            }
            j++;
        }return cur;
    }
};