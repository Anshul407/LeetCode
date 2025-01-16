class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //xor associative law  (a^b)^(a^c)=(b^c)
       if(nums1.size()%2==0&&nums2.size()%2==0)return 0;
       if(nums1.size()%2!=0&&nums2.size()%2!=0){
        int cur=0;
        for(auto i:nums1)cur^=i;
        for(auto i:nums2)cur^=i;
        return cur;
       }
       int cur=0;
       if(nums1.size()%2==0){
        for(auto i:nums1)cur^=i;
       }
       if(nums2.size()%2==0){
        for(auto i:nums2)cur^=i;
       }
       return cur;
    }
};