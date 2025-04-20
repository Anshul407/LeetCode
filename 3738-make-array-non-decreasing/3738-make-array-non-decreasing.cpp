class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cur=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(cur==-1){
                cur=nums[i];
                ans++;
            }
            else{
                if(cur<=nums[i]){
                    cur=nums[i];
                    ans++;
                }
            }
        }return ans;
    }
};