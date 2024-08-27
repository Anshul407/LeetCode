class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       map<int,int>mp;
        for(auto &i:time){
            i%=60;
        }
        int ans=0;
        mp[60]++;
        for(auto i:time){
            int num=i;
            if(i!=0)
            num=60-i;
            
            if(mp.find(num)!=mp.end())ans+=mp[num];
            mp[i]++;
        }
        
        return ans;

        
    }
};