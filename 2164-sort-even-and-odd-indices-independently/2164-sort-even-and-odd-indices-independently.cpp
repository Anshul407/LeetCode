class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>x,y;
        for(int i=0;i<nums.size();i+=2){
            x.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i+=2){
            y.push_back(nums[i]);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        reverse(y.begin(),y.end());

        vector<int>ans(nums.size(),0);
        int f=1;
        for(auto &i:ans){
            if(f){
                i=x[0];
                x.erase(x.begin()+0);
                f=0;
            }else{
                i=y[0];
                y.erase(y.begin()+0);
                f=1;
            }
        }
        return ans;
    }
};