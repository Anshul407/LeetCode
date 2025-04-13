class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2)return 0;
        int maxi=nums.size();
        int i=0;
        while(pow(2,i)<=maxi){
            i++;
        }
        return pow(2,i);
       
    }
};