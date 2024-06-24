class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool a=nums[0]==nums[1];
        bool aa=nums[1]==nums[2];

        
        if(a&aa)return "equilateral";

        bool b=nums[0]==nums[1];
        bool c=nums[0]==nums[2];
        bool d=nums[1]==nums[2];
        if(c||d||b)return "isosceles";
       
        bool xx=nums[0]+nums[1]>nums[2];
        bool y=nums[0]+nums[2]>nums[1];
        bool z=nums[2]+nums[1]>nums[0];
        if(xx&&y&&z)return "scalene";

        return "none";
    }
};