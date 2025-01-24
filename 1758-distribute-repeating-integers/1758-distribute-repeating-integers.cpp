class Solution {
public:
    
    int solve(unordered_map<int,int>&mp,vector<int>&q,int i){
        if(i>=q.size())return 1;
        for(auto &x:mp){
            if(x.second>=q[i]){
                x.second-=q[i];
                int cur=solve(mp,q,i+1);
                if(cur)return 1;
                 x.second+=q[i];

            }
        }return 0;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        sort(quantity.rbegin(), quantity.rend());
        return solve(mp,quantity,0);
       
    }
};