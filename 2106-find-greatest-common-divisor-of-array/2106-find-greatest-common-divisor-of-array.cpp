class Solution {
public:
    int solve(int a,int b){
        if(a<b){
            for(int i=a;i>=1;i--){
                if(a%i==0&&b%i==0)return i;
            }
        }else{
            for(int i=b;i>=1;i--){
                if(a%i==0&&b%i==0)return i;
            }
        }
        return 1;
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums.back();

        return solve(a,b);
    }
};