class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int ind, int vd) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j)continue;
                if(abs(i-j)>=ind&&abs(nums[i]-nums[j])>=vd){
                    return {i,j};
                }
            }
        }
        return {-1,-1};

    }
};