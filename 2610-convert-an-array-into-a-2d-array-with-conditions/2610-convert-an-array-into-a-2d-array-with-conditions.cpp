class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        while(true){
            vector<int>x;
            for(auto &i:mp){
                if(i.second){
                x.push_back(i.first);
                i.second--;
                }    
            }
            if(!x.empty())ans.push_back(x);
            else return ans;

        }
        return ans;
    }
};