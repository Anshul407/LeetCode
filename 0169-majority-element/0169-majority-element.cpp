class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur=0;
        int ele=-1;
        for(auto i:nums){
            if(cur==0){
                ele=i;
            }
            if(ele==i)cur++;
            else cur--;
        }return ele;
    }
};