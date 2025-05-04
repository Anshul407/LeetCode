class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        for(auto i:dominoes){
            if(i[0]<i[1]){
                mp[{i[0],i[1]}]++;
            }else mp[{i[1],i[0]}]++;
        }
        int cnt=0;
        for(auto i:mp){
            if(i.second==2)cnt++;
            else if(i.second>1){
                cnt+=(i.second*(i.second-1)/2);
            }
        }return cnt;
    }
};