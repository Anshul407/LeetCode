class Solution {
public:
    vector<vector<int>>ans;
    unordered_set<int>st;
    void solve(vector<int>&nums,vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(st.find(i)!=st.end())continue;
            st.insert(i);
            temp.push_back(nums[i]);
            solve(nums,temp);
            temp.pop_back();
            st.erase(i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       int index=0;
       vector<int>temp;
       solve(nums,temp);
       return ans;

    }
};
