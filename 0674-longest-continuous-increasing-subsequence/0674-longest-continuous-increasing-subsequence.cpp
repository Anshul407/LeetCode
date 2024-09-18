class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cur=0;
        int ans=0;
        int p=-1;
        for(auto i:nums){
            if(p<i){
                p=i;
                cur++;
            }
            else{
                ans=max(cur,ans);
                cur=1;
                p=-1;
            }
            
        }
        return max(ans,cur);
    }
};