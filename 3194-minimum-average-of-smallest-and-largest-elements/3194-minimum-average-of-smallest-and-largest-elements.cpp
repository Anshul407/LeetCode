class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x=nums.size()/2;
        int i=0,j=nums.size()-1;
        double ans=932874873874.0;
        while(i<j&&x){
            double num=nums[i]+nums[j];
            num/=2.0;
            cout<<num<<" ";
            ans=min(ans,num);
            x++;
            i++;
            j--;

        }
        return ans;
    }
};