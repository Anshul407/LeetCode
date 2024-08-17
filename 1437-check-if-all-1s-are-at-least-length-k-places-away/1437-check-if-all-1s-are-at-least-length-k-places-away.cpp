class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int ind=0;
        while(ind<nums.size()&&nums[ind]==0){
            ind++;
        }
        int cur=ind;
        for(int i=ind;i<nums.size();i++){
            if(nums[i]==1&&i!=cur){
                if(i-cur<=k)return 0;

                cur=i;
            }
        }
        return 1;
    }
};