class Solution {
public:
    bool check(vector<int>&a){
        for(int i=1;i<a.size();i++){
            if(a[i]<a[i-1])return 0;
        }return 1;
    }
    int minimumRightShifts(vector<int>& nums) {
        vector<int>a,b;
        int f=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                f=i;
                break;
            }
        }
        if(!f)return 0;
        for(int i=0;i<f;i++){
            a.push_back(nums[i]);
        }
        for(int i=f;i<nums.size();i++)b.push_back(nums[i]);
        if(b.back()>a[0])return -1;
        if(check(a)&&check(b))return nums.size()-f;
        return -1;
        

    }
};