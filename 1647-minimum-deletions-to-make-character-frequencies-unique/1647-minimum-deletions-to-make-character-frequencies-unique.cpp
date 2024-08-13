class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        map<int,int>mp2;
        for(auto i:mp){
            mp2[i.second]++;
        }
        int ans=0;
        for(auto i:mp2){
            int x=i.second;
            int num=i.first;
            while(x>1){
                int n=num;
                while(mp2[n]&&n>0){
                    n--;
                    ans++;
                }
                
                mp2[n]++;
                x--;
                
            }
        }
        return ans;

    }
};