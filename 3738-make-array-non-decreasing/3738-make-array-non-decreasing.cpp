class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cur=-1;
        int ind=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(cur==-1){
                ind=i;
                cur=nums[i];
                ans++;
            }
            else{
                if(cur<=nums[i]){
                    ind=i;
                    cur=nums[i];
                    ans++;
                }
            }
        }return ans;
    }
};