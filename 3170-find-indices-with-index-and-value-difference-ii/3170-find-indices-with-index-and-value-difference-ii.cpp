class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        auto i=id;
        int a=0,b=0;
        int maxi=nums[0],mini=nums[0];
        while(i<nums.size()){
            if(nums[i-id]>maxi){
                maxi=nums[i-id];
                a=i-id;
            }
            if(nums[i-id]<mini){
                mini=nums[i-id];
                b=i-id;
            }

            if(abs(nums[i]-nums[a])>=vd)return {a,i};
            if(abs(nums[i]-nums[b])>=vd)return {b,i};
            i++;
        }
        return {-1,-1};
    }
};