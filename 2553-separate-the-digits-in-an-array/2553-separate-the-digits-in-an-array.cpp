class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums){
            string x=to_string(i);
            for(auto j:x){
                
                ans.push_back(j-'0');
            }
        }
        return ans;
    }
};