class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
       
        map<int,int>mp,mp2;
        for(auto i:nums){
            mp[i]++;
            mp2[i]++;
        }
        int ans=0;
        int prev=-1;
       
        for(auto i:mp){
            if(i.second>1){
                int cnt=i.second;
                 
                 int cur=0;
                 if(prev!=-1)cur=prev-i.first;
                while(cnt>1){
                    int num;
                    if(prev>i.first)num=prev;
                    else num=i.first;
                    while(mp2[num]){
                        num++;
                        cur++;
                    }
                    ans+=cur;
                    prev=num;
                    mp2[num]=1;
                    cnt--;
                }
            }
        }
        return ans;
    }
};