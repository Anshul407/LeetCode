class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0||right==0)return 0;
        if((int)log2(left)!=(int)log2(right)) return 0; 
        int ans=left;
        while(left<right){
            ans&=++left;
        }
        return ans;
    }
};