class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size()){
            if(j-i>k){
               i++;
            }
            else{
                if(nums[i]==nums[j]&&i!=j){
                    return true;
                    break;
                }
               
                else{
                    int x=i;
                    while(x!=j){
                        if(nums[x]==nums[j]){return true;break;}
                        x++;
                    }
                    j++;
                }

            }
        }
        return false;
    }
};