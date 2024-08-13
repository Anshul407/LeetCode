class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int k=0;
        int ans=0;
        while(i<s.length()&&j<s.length()){
            k++;
            mp[s[j]]++;
           
            if(k==3){
                if(mp[s[i]]>1||mp[s[i+1]]>1||mp[s[i+2]]>1){
                    k--;
                    mp[s[i]]--;
                    i++;
                   
                }
                else{
                    k--;
                    mp[s[i]]--;
                    i++;
                    ans++;
                }
            }
             j++;
        }

        return ans;
    }
};