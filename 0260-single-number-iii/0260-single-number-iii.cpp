class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(auto i :nums){
            xorr^=i;
        }
        int rightmost=xorr^(xorr&(xorr-1));
        int b1=0,b2=0;
         for(auto i :nums){
            if(rightmost&i)b1^=i;
            else{
                b2^=i;
            }
        }
        return{b1,b2};
    }
};