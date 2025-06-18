class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            int cur=nums[i];
            int cnt=0;
            while(i<nums.size()&&nums[i]-cur<=k&&cnt<3){
                temp.push_back(nums[i]);
                i++;
                cnt++;
            }
            i--;
            if(cnt<3)return {};
            ans.push_back(temp);
        }
        return ans;
    }
};