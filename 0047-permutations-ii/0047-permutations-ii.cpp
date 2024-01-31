class Solution {
public:
    void mp(vector<int>nums,vector<int>op,vector<vector<int>>&ans){
        if(nums.size()==0){
            ans.push_back(op);
            return ;
        }
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0){
                m[nums[i]]++;
                vector<int>nums2(nums);
                vector<int>op1(op);
                op1.push_back(nums[i]);
                nums2.erase(nums2.begin()+i);
                mp(nums2,op1,ans);
                op1.pop_back();
            }
            else continue;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        mp(nums,op,ans);
        return ans;
    }
};