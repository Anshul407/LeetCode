class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries){
            int val=it[0];
            int ind=it[1];
            nums[ind]+=val;
            int currsum=0;
            for(auto i:nums){
                if(i%2==0)currsum+=i;
            }
            ans.push_back(currsum);
        }
        return ans;
    }
};